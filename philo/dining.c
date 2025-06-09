/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:13:50 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 13:47:35 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, int *count_meal)
{
	if (philo->philo_id % 2 == 0)
	{
		usleep(1000);
		pthread_mutex_lock(philo->l_fork);
		print_status(4, philo);
		pthread_mutex_lock(philo->r_fork);
		print_status(3, philo);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(3, philo);
		pthread_mutex_lock(philo->l_fork);
		print_status(4, philo);
	}
	print_status(5, philo);
	(*count_meal)++;
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_time = get_elapsed_time(philo->table->start_time);
	pthread_mutex_unlock(&philo->table->meal_mutex);
	ft_usleep(philo->table, philo->table->time_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	check_this_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meal_mutex);
	if (philo->is_full)
	{
		pthread_mutex_unlock(&philo->table->meal_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->meal_mutex);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->dead)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
	return (1);
}

void	*routine(void *args)
{
	t_philo	*philo;
	int		count_meal;

	count_meal = 0;
	philo = (t_philo *)args;
	while (1)
	{
		if (!check_this_one(philo))
			break ;
		eat(philo, &count_meal);
		pthread_mutex_lock(&philo->table->meal_mutex);
		if (count_meal == philo->table->max_meal)
		{
			philo->is_full = 1;
			pthread_mutex_unlock(&philo->table->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->meal_mutex);
		print_status(1, philo);
		ft_usleep(philo->table, philo->table->time_sleep);
		print_status(2, philo);
	}
	return (0);
}

void	dining(t_table *table)
{
	int	i;

	i = 0;
	gettimeofday(&(table->start_time), NULL);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->philo[i].philo, NULL, &routine,
				&table->philo[i]) != 0)
			return ;
		i++;
	}
}

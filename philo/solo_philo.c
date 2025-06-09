/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:28:26 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 13:46:24 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_table *table)
{
	table->fork = malloc(sizeof(pthread_mutex_t));
	table->philo = malloc(sizeof(t_philo));
	if (!table->philo || !table->fork)
	{
		free(table->fork);
		free(table->philo);
		return ;
	}
	if (pthread_mutex_init(table->fork, NULL) != 0)
		return ;
	table->philo->is_dead = 0;
	table->philo->is_full = 0;
	table->philo->l_fork = NULL;
	table->philo->last_meal_time = 0;
	table->philo->philo_id = 0;
	table->philo->r_fork = table->fork;
	table->philo->table = table;
}

void	*solo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->r_fork);
	print_status(3, philo);
	while (1)
	{
		pthread_mutex_lock(&philo->table->death_mutex);
		if (philo->table->dead)
		{
			pthread_mutex_unlock(&philo->table->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->death_mutex);
		usleep(5000);
	}
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

void	dining_philo(t_table *table)
{
	gettimeofday(&(table->start_time), NULL);
	if (pthread_create(&table->philo->philo, NULL, &solo_routine,
			table->philo) != 0)
		return ;
}

void	check_philo_dead(t_table *table)
{
	while (1)
	{
		if ((get_elapsed_time(table->start_time)
				> (unsigned long long)table->time_die))
		{
			pthread_mutex_lock(&table->death_mutex);
			table->dead = 1;
			pthread_mutex_unlock(&table->death_mutex);
			print_status(6, table->philo);
			return ;
		}
		usleep(5000);
	}
}

void	solo_dolo(t_table *table)
{
	init_philo(table);
	dining_philo(table);
	check_philo_dead(table);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:20:07 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 17:32:29 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_table *table, unsigned long long time_ms)
{
	unsigned long long	start;

	start = get_current_time();
	while (get_current_time() - start < time_ms)
	{
		pthread_mutex_lock(&table->death_mutex);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->death_mutex);
		usleep(250);
	}
}

int	another_check(t_table *table)
{
	pthread_mutex_lock(&table->death_mutex);
	if (table->dead)
	{
		pthread_mutex_unlock(&table->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table->death_mutex);
	return (1);
}

void	print_status(int state, t_philo *philo)
{
	if (another_check(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		print_utils(state, philo);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		if (state == 6)
			printf(B_R"[%llu] the Philo %ld is dead\n"RST,
				get_elapsed_time(philo->table->start_time), philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
}

void	end_simu(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->philo[i].philo, NULL) != 0)
			printf("Erreur join\n");
		i++;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&table->meal_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	if (table->philo)
		free(table->philo);
	if (table->fork)
		free(table->fork);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac < 5 || ac > 6)
		exit_error("Bad argument number");
	pars_args(&table, ac, av);
	if (table.nb_philo > 1)
	{
		init_all(&table);
		dining(&table);
		death_check(&table);
	}
	else
		solo_dolo(&table);
	end_simu(&table);
	return (0);
}

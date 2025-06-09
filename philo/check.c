/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:37:26 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 13:46:42 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_full_check(t_table *table)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&table->meal_mutex);
	while (i < table->nb_philo)
	{
		if (table->philo[i].is_full)
			count++;
		i++;
	}
	pthread_mutex_unlock(&table->meal_mutex);
	if (count == table->nb_philo)
		return (1);
	return (0);
}

void	death_check(t_table *table)
{
	int	i;

	while (table->max_meal == -1 || !all_full_check(table))
	{
		i = 0;
		while (i < table->nb_philo)
		{
			pthread_mutex_lock(&table->meal_mutex);
			if ((get_elapsed_time(table->start_time)
					- table->philo[i].last_meal_time)
				> (unsigned long long)table->time_die)
			{
				pthread_mutex_lock(&table->death_mutex);
				table->dead = 1;
				pthread_mutex_unlock(&table->death_mutex);
				print_status(6, &table->philo[i]);
				pthread_mutex_unlock(&table->meal_mutex);
				return ;
			}
			pthread_mutex_unlock(&table->meal_mutex);
			i++;
		}
		usleep(5000);
	}
}

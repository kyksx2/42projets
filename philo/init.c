/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:34:31 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 10:57:02 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_all(t_table *table)
{
	int	i;
	int	j;

	table->fork = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	table->philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philo || !table->fork)
	{
		free(table->fork);
		free(table->philo);
		return ;
	}
	j = -1;
	while (++j < table->nb_philo)
		pthread_mutex_init(&table->fork[j], NULL);
	i = -1;
	while (++i < table->nb_philo)
	{
		table->philo[i].is_dead = 0;
		table->philo[i].is_full = 0;
		table->philo[i].l_fork = &table->fork[i];
		table->philo[i].last_meal_time = 0;
		table->philo[i].philo_id = i;
		table->philo[i].r_fork = &table->fork[(i + 1) % table->nb_philo];
		table->philo[i].table = table;
	}
}

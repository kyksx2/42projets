/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:00:24 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 10:56:12 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(char *str)
{
	int		i;

	i = 0;
	if (len(str) > 10)
		exit_error("Error: Bad argument");
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			exit_error("Error: Bad argument");
	}
}

long	ft_atol(char *str)
{
	int		i;
	int		signe;
	long	nb;

	nb = 0;
	signe = 1;
	i = 0;
	check_args(str);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}

long	safe_atol(char *str)
{
	long	res;

	res = ft_atol(str);
	if (res < -2147483648 || res > 2147483647)
		exit_error("Error: Bad argument");
	return (res);
}

void	pars_args(t_table *table, int ac, char **av)
{
	table->nb_philo = safe_atol(av[1]);
	table->time_die = safe_atol(av[2]);
	table->time_eat = safe_atol(av[3]);
	table->time_sleep = safe_atol(av[4]);
	table->dead = 0;
	table->all_full = 0;
	if (ac == 6)
		table->max_meal = safe_atol(av[5]);
	else
		table->max_meal = -1;
	if (table->nb_philo <= 0 || table->time_die <= 0 || table->time_eat <= 0
		|| table->time_sleep <= 0 || (ac == 6 && table->max_meal <= 0))
		exit_error("Error: invalide arguments");
	if (pthread_mutex_init(&table->meal_mutex, NULL) != 0
		|| pthread_mutex_init(&table->print_mutex, NULL) != 0
		|| pthread_mutex_init(&table->death_mutex, NULL) != 0)
		exit_error("mutex init error");
}

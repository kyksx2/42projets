/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:03:53 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 11:19:34 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_utils(int state, t_philo *philo)
{
	if (state == 1)
		printf(B"[%llu] the Philo %ld sleep\n"RST,
			get_elapsed_time(philo->table->start_time), philo->philo_id);
	if (state == 2)
		printf(G"[%llu] the Philo %ld think\n"RST,
			get_elapsed_time(philo->table->start_time), philo->philo_id);
	if (state == 3)
		printf(Y"[%llu] the Philo %ld take the rigth fork\n"RST,
			get_elapsed_time(philo->table->start_time), philo->philo_id);
	if (state == 4)
		printf(Y"[%llu] the Philo %ld take the left fork\n"RST,
			get_elapsed_time(philo->table->start_time), philo->philo_id);
	if (state == 5)
		printf("[%llu] the Philo %ld is eating\n"RST,
			get_elapsed_time(philo->table->start_time), philo->philo_id);
}

unsigned long long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long long	get_elapsed_time(struct timeval start_time)
{
	return (get_current_time()
		- ((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000)));
}

void	exit_error(char *str)
{
	printf(B_R"%s\n"RST, str);
	exit (EXIT_FAILURE);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

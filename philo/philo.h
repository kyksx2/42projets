/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:20:27 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/22 17:34:04 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

/* code ANSI -> color le texte */
# define RST	"\033[0m"
# define R		"\033[31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define B_R	"\033[1;31m"

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t			philo;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	long				philo_id;
	int					is_full;
	int					is_dead;
	unsigned long long	last_meal_time;
	t_table				*table;
}	t_philo;

typedef struct s_table
{
	long			nb_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			max_meal;
	struct timeval	start_time;
	int				all_full;
	int				dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philo;
}	t_table;

/* dining */
void				eat(t_philo *philo, int *count_meal);
int					check_this_one(t_philo *philo);
void				*routine(void *args);
void				dining(t_table *table);
/* init */
void				init_all(t_table *table);
/* main */
void				print_status(int state, t_philo *philo);
void				end_simu(t_table *table);
int					another_check(t_table *table);
void				ft_usleep(t_table *table, unsigned long long time_ms);
/* parsing */
void				check_args(char *str);
long				ft_atol(char *str);
long				safe_atol(char *str);
void				pars_args(t_table *table, int ac, char **av);
/* utils */
void				exit_error(char *str);
int					len(char *str);
unsigned long long	get_current_time(void);
unsigned long long	get_elapsed_time(struct timeval start_time);
void				print_utils(int state, t_philo *philo);
/* check */
void				death_check(t_table *table);
int					all_full_check(t_table *table);
/* solo_philo */
void				solo_dolo(t_table *table);
void				init_philo(t_table *table);
void				dining_philo(t_table *table);
void				*solo_routine(void *data);
void				check_philo_dead(t_table *table);

#endif
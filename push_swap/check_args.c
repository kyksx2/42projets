/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:38:58 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/03 18:47:49 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_input(char **args)
{
	int			i;
	int			nb_zero;
	long int	tmp;

	i = 0;
	nb_zero = 0;
	tmp = 0;
	while (args[i])
	{
		if (!arg_is_number(args[i]))
			return (0);
		tmp = ft_atol(args[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (0);
		nb_zero += is_zero(args[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (has_dupliacte(args))
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 1;
	if (argc == 2)
	{
		args = ft_split(argv[i], ' ');
		i = 0;
	}
	else
		args = argv;
	if (!correct_input(&args[i]))
	{
		if (argc == 2)
			ft_free(args);
		return (0);
	}
	if (argc == 2)
		ft_free(args);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:28:54 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/31 14:29:25 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_signe(argv[i]))
		i++;
	while (argv[i])
	{
		if (argv[i] != '\0' && !ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_signe(char c)
{
	return (c == '+' || c == '-');
}

int	is_zero(char *args)
{
	int	i;

	i = 0;
	if (is_signe(args[i]))
		i++;
	while (args[i] && args[i] == '0')
		i++;
	if (args[i] != '\0')
		return (0);
	return (1);
}

int	args_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[i] != '+')
			i++;
	}
	else
		if (s2[j] == '+')
			j++;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

int	has_dupliacte(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (args_cmp(args[i], args[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:56:48 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/10 12:18:35 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_av(char *argv, int i)
{
	char	*cmp;
	int		j;

	j = 0;
	cmp = ".ber";
	while (argv[i])
	{
		if (argv[i] != cmp[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	first_check(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		print_error("Error: bad argument number");
	i = ft_strlen(argv[1]) - 4;
	if (!check_av(argv[1], i))
		print_error("Error: choisir un fichier '.ber'");
}

void	print_error(char *s)
{
	ft_putendl_fd(s, 1);
	exit(1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

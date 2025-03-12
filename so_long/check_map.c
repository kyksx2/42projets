/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:57:55 by kjolly            #+#    #+#             */
/*   Updated: 2025/03/05 15:51:53 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_data *data)
{
	unsigned long	i;
	unsigned long	width;

	i = 0;
	width = ft_strlen(data->grid[0]);
	while (data->grid[i])
	{
		if ((ft_strlen(data->grid[i])) != width)
			return (0);
		i++;
	}
	if (width == i)
		return (0);
	data->width = width;
	data->height = i;
	return (1);
}

int	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!data || !data->grid)
		return (0);
	while (j < data->width)
	{
		if (data->grid[0][j] != '1' || data->grid[data->height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < data->height)
	{
		if (data->grid[i][0] != '1' || data->grid[i][data->width -1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_content(t_data *data)
{
	int	count_e;
	int	count_p;
	int	count_c;

	count_c = 0;
	count_e = 0;
	count_p = 0;
	if (!count_element(data, count_e, count_p, count_c))
		return (0);
	return (1);
}

int	check_map_path(char **map, t_data *data)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (map[y][x] == 'P')
			{
				player_y = y;
				player_x = x;
			}
			x++;
		}
		y++;
	}
	data->exit_reachable = 0;
	flood_fill(map, player_x, player_y, data);
	if (!re_check(map, data))
		return (0);
	return (1);
}

int	check_map(t_data *data)
{
	char	**str;

	if (!check_rectangle(data))
		return (ft_printf("Error: la map n'est pas un rectangle"), 0);
	if (!check_wall(data))
		return (ft_printf("Error: il manque du mural"), 0);
	if (!check_map_content(data))
		return (ft_printf("Error : probleme de contenue"), 0);
	str = map_dup(data);
	if (!str)
		return (0);
	if (!check_map_path(str, data))
	{
		free_tab(str);
		ft_printf("Error: le chemin vers  la sortie n'est pas bon");
		return (0);
	}
	free_tab(str);
	return (1);
}
 
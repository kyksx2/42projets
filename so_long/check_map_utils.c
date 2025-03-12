/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:13:40 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/08 14:35:11 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_content(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

char	**map_dup(t_data *data)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (data->height + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < data->height)
	{
		tmp[i] = ft_strdup(data->grid[i]);
		if (!tmp[i])
		{
			free_tab(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	else if (map[y][x] == 'E')
	{
		data->exit_reachable = 1;
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

int	re_check(char **map, t_data *data)
{
	int	x;
	int	y;
	int	collec;
	int	exit_found;

	y = 0;
	collec = 0;
	exit_found = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (map[y][x] == 'C')
				collec++;
			x++;
		}
		y++;
	}
	if (collec != 0 || data->exit_reachable == 0)
		return (0);
	return (1);
}

int	count_element(t_data *data, int e, int p, int c)
{
	int	i;
	int	j;

	i = 1;
	while (data->grid[i])
	{
		j = 0;
		while (data->grid[i][j])
		{
			if (!valid_content(data->grid[i][j]))
				return (0);
			if (data->grid[i][j] == 'E')
				e++;
			if (data->grid[i][j] == 'P')
				p++;
			if (data->grid[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (e > 1 || p > 1 || c < 1)
		return (0);
	data->count_collec = c;
	return (1);
}

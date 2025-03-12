/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_moov_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:38:52 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/08 13:40:03 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collec(char c, int collec)
{
	if (c == 'E')
		collec--;
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->grid[y])
	{
		x = 0;
		while (data->grid[y][x])
		{
			put_img(data->grid[y][x], y, x, data);
			x++;
		}
		y++;
	}
}

void	find_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == 'P')
			{
				data->pos_y = y;
				data->pos_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

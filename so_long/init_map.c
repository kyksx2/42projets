/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:51:44 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/08 13:31:18 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *data)
{
	data->ellements.perso.img = mlx_xpm_file_to_image
		(data->mlx, "./images/perso.xpm",
			&data->ellements.perso.widht, &data->ellements.perso.height);
	data->ellements.wall.img = mlx_xpm_file_to_image
		(data->mlx, "./images/wall.xpm",
			&data->ellements.wall.widht, &data->ellements.wall.height);
	data->ellements.floor.img = mlx_xpm_file_to_image
		(data->mlx, "./images/floor.xpm",
			&data->ellements.floor.widht, &data->ellements.floor.height);
	data->ellements.collectible.img = mlx_xpm_file_to_image
		(data->mlx, "./images/collectible.xpm",
			&data->ellements.collectible.widht,
			&data->ellements.collectible.height);
	data->ellements.end.img = mlx_xpm_file_to_image
		(data->mlx, "./images/exit.xpm",
			&data->ellements.end.widht, &data->ellements.end.height);
	if (!data->ellements.perso.img || !data->ellements.wall.img
		|| !data->ellements.floor.img || !data->ellements.collectible.img
		|| !data->ellements.end.img)
	{
		endgame(data);
		exit(EXIT_FAILURE);
	}
}

void	put_img(char c, int i, int j, t_data *data)
{
	if (c == '1')
		mlx_put_image_to_window
		(data->mlx, data->win, data->ellements.wall.img, j * 80, i * 80);
	if (c == '0')
		mlx_put_image_to_window
		(data->mlx, data->win, data->ellements.floor.img, j * 80, i * 80);
	if (c == 'P')
		mlx_put_image_to_window
		(data->mlx, data->win, data->ellements.perso.img, j * 80, i * 80);
	if (c == 'C')
		mlx_put_image_to_window
		(data->mlx, data->win, data->ellements.collectible.img, j * 80, i * 80);
	if (c == 'E')
		mlx_put_image_to_window
		(data->mlx, data->win, data->ellements.end.img, j * 80, i * 80);
}

void	init_img(t_data *data)
{
	int	i;
	int	j;

	load_img(data);
	i = 0;
	while (data->grid[i])
	{
		j = 0;
		while (data->grid[i][j])
		{
			put_img(data->grid[i][j], i, j, data);
			j++;
		}
		i++;
	}
}

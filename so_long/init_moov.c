/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_moov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:55:32 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/08 16:58:56 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_action(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		endgame(data);
	if (keycode == XK_w || keycode == XK_Up || keycode == XK_a
		|| keycode == XK_Left || keycode == XK_s || keycode == XK_Down
		|| keycode == XK_d || keycode == XK_Right)
		init_moov(keycode, data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (0);
}

void	init_moov(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_Up)
		moov_da_player(data, -1, 0);
	if (keycode == XK_a || keycode == XK_Left)
		moov_da_player(data, 0, -1);
	if (keycode == XK_s || keycode == XK_Down)
		moov_da_player(data, 1, 0);
	if (keycode == XK_d || keycode == XK_Right)
		moov_da_player(data, 0, 1);
}

void	moov_da_player(t_data *data, int y_add, int x_add)
{
	char	futur_pos;
	int		x;
	int		y;

	find_pos(data);
	x = data->pos_x;
	y = data->pos_y;
	futur_pos = data->grid[y + y_add][x + x_add];
	if (futur_pos == '1')
		return ;
	if (futur_pos == 'C')
		data->count_collec -= 1;
	if (futur_pos == 'E')
	{
		if (data->count_collec > 0)
			return ;
		endgame(data);
	}
	data->grid[y][x] = '0';
	data->grid[y + y_add][x + x_add] = 'P';
	data->key_count++;
	ft_printf("compteur : %d\n", data->key_count);
}

int	endgame(t_data *data)
{
	if (data->grid)
		free_tab(data->grid);
	if (data->ellements.collectible.img)
		mlx_destroy_image(data->mlx, data->ellements.collectible.img);
	if (data->ellements.end.img)
		mlx_destroy_image(data->mlx, data->ellements.end.img);
	if (data->ellements.perso.img)
		mlx_destroy_image(data->mlx, data->ellements.perso.img);
	if (data->ellements.wall.img)
		mlx_destroy_image(data->mlx, data->ellements.wall.img);
	if (data->ellements.floor.img)
		mlx_destroy_image(data->mlx, data->ellements.floor.img);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

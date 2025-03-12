/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:20:33 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/13 14:47:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

// escape == XK_Escape
// w == XK_w
// a == XK_a
// s == XK_s
// d == XK_d
// fleche haut == XK_Up
// fleche bas == XK_Down
// fleche droite == XK_Right
// fleche gauche == XK_Left

typedef struct s_img
{
	void	*img;
	int		height;
	int		widht;
}	t_img;

typedef struct s_ellements
{
	t_img	perso;
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	end;
}	t_ellements;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**grid;
	int			height;
	int			width;
	int			pos_x;
	int			pos_y;
	int			exit_reachable;
	int			key_count;
	int			count_collec;
	t_ellements	ellements;
}	t_data;

void	read_map(t_data *data, char *argv);
/*check carte*/
int		check_rectangle(t_data *data);
int		check_wall(t_data *data);
int		check_map_content(t_data *data);
int		count_element(t_data *data, int e, int p, int c);
int		check_map_path(char **map, t_data *data);
int		check_map(t_data *data);
int		valid_content(char c);
void	flood_fill(char **map, int x, int y, t_data *data);
int		re_check(char **map, t_data *data);
char	*join_map(char *str, int fd);
int		check_double_line(char *str);
char	**map_dup(t_data *data);
/*initialisation de la map*/
void	init_img(t_data *data);
void	load_img(t_data *data);
void	put_img(char c, int i, int j, t_data *data);
/*initialisation des mouvements*/
int		key_action(int keycode, void *param);
int		endgame(t_data *data);
void	find_pos(t_data *data);
void	draw_map(t_data *data);
void	init_moov(int keycode, t_data *data);
void	check_collec(char c, int collec);
void	moov_da_player(t_data *data, int y_add, int x_add);
/*utils*/
void	print_error(char *s);
void	free_tab(char **tab);
void	first_check(int argc, char **argv);
int		check_av(char *argv, int i);

#endif
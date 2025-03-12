/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:19:16 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/12 15:25:11 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_double_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join_map(char *str, int fd)
{
	char	*tmp;
	char	*new_tmp;

	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	while (str)
	{	
		new_tmp = ft_strjoin(tmp, str);
		free(tmp);
		if (!new_tmp)
		{
			free(str);
			return (close(fd), NULL);
		}
		tmp = new_tmp;
		free(str);
		str = get_next_line(fd);
	}
	if (check_double_line(tmp))
	{
		free(tmp);
		print_error("Erreur : a quoi tu joue, mauvaise map");
	}
	return (tmp);
}

void	read_map(t_data *data, char *argv)
{
	char	*tmp;
	char	*str;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	tmp = join_map(str, fd);
	if (!tmp)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	data->grid = ft_split(tmp, '\n');
	free(tmp);
	if (!data->grid)
	{
		free(tmp);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	first_check(argc, argv);
	read_map(&data, argv[1]);
	if (!check_map(&data))
	{
		free_tab(data.grid);
		exit (1);
	}
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_printf("Error : put the gun down");
		free_tab(data.grid);
		return (0);
	}
	data.win = mlx_new_window
		(data.mlx, data.width * 80, data.height * 80, "so_long");
	init_img(&data);
	data.key_count = 0;
	mlx_hook(data.win, 2, 1L << 0, key_action, &data);
	mlx_hook(data.win, 17, 0, endgame, &data);
	mlx_loop(data.mlx);
	return (0);
}

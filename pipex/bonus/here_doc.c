/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:26:54 by kjolly            #+#    #+#             */
/*   Updated: 2025/03/08 14:56:24 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	here_cmp(char *line, char *limiteur)
{
	size_t	size_line;
	size_t	size_limiteur;

	size_line = ft_strlen(line) - 1;
	size_limiteur = ft_strlen(limiteur);
	if (size_limiteur ==  size_line)
	{
		if(ft_strncmp(line, limiteur, size_limiteur) == 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

void	here_doc(t_pipex *data)
{
	char	*line;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit_error("Error: pipe failed", 1);
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line || here_cmp(line, data->limiteur) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[1]);
	data->fd_transfer = pipe_fd[0];
}

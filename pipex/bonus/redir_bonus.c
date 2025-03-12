/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:00:45 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/17 15:48:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_file_bonus(t_pipex *data)
{
	close(data->in);
	close(data->out);
}

void	redir_last(t_pipex *data)
{
	dup2(data->fd_transfer, 0);
	close(data->fd_transfer);
	dup2(data->out, 1);
	close(data->out);
}

void	redir_rest(t_pipex *data, int *pipe_fd)
{
	dup2(data->fd_transfer, 0);
	close(data->fd_transfer);
	close(data->out);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
}

void	redir_first(t_pipex *data, int *pipe_fd)
{
	dup2(data->in, 0);
	close(data->in);
	close(data->out);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
}

void	redir_here_doc(t_pipex *data, int *pipe_fd)
{
	dup2(data->fd_transfer, 0);
	close(data->fd_transfer);
	close(data->out);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
}

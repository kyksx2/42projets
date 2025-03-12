/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:01:27 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/17 16:09:36 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	last_cmd(t_pipex *data)
{
	if (!data->out)
		return ;
	data->pidarray[data->cmd_count - 1] = fork();
	if (data->pidarray[data->cmd_count - 1] == -1)
	{
		close_file_bonus(data);
		free(data->pidarray);
		exit_error("Error: pipe failed", 1);
	}
	else if (data->pidarray[data->cmd_count - 1] == 0)
	{
		redir_last(data);
		exec_bonus(data, data->cmd[data->cmd_count - 1], data->envp);
	}
	else
	{
		close(data->fd_transfer);
		close(data->out);
	}
}

void	rest_cmd(t_pipex *data, int i)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		close_file_bonus(data);
		free(data->pidarray);
		exit_error("Error: pipe failed", 1);
	}
	data->pidarray[i] = fork();
	if (data->pidarray[i] == -1)
	{
		close_file_bonus(data);
		free(data->pidarray);
		exit_error("Error: fork failed", 1);
	}
	else if (data->pidarray[i] == 0)
	{
		redir_rest(data, pipe_fd);
		exec_bonus(data, data->cmd[i], data->envp);
	}
	close(pipe_fd[1]);
	close(data->fd_transfer);
	data->fd_transfer = pipe_fd[0];
}

void	first_cmd_multi_pipe(t_pipex *data)
{
	int	pipe_fd[2];

	if (!data->in)
		return ;
	if (pipe(pipe_fd) == -1)
	{
		close_file_bonus(data);
		free(data->pidarray);
		exit_error("Error: pipe failed", 1);
	}
	data->pidarray[0] = fork();
	if (data->pidarray[0] == -1)
	{
		close_file_bonus(data);
		free(data->pidarray);
		exit_error("Error: fork failed", 1);
	}
	else if (data->pidarray[0] == 0)
	{
		redir_first(data, pipe_fd);
		exec_bonus(data, data->cmd[0], data->envp);
	}
	close(pipe_fd[1]);
	close(data->in);
	data->fd_transfer = pipe_fd[0];
}

void	first_cmd_here_doc(t_pipex *data)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		close_file_bonus(data);
		free(data->pidarray);
		exit_error("Error: pipe failed", 1);
	}
	data->pidarray[0] = fork();
	if (data->pidarray[0] == -1)
	{
		close_file_bonus(data);
		free(data->pidarray);
		exit_error("Error: pipe failed", 1);
	}
	else if (data->pidarray[0] == 0)
	{
		redir_here_doc(data, pipe_fd);
		exec_bonus(data, data->cmd[0], data->envp);
	}
	close(pipe_fd[1]);
	close(data->fd_transfer);
	data->fd_transfer = pipe_fd[0];
}

void	first_cmd(t_pipex *data, int setup)
{
	if (setup == 1)
	{
		here_doc(data);
		first_cmd_here_doc(data);
	}
	else if (setup == 0)
		first_cmd_multi_pipe(data);
}

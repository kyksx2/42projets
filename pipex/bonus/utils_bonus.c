/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:15:03 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/25 15:33:03 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_here_out(int in, int ac, char **av)
{
	int	out;

	if (access(av[ac - 1], F_OK) == 0)
	{
		if (access(av[ac - 1], W_OK) == -1)
		{
			close(in);
			exit_error("pipex", 1);
		}
	}
	out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (out == -1)
	{
		close(in);
		exit_error("Error: cannot open file2", 1);
	}
	return (out);
}

int	open_file_out(int ac, char **av)
{
	int	out;

	if (access(av[ac - 1], F_OK) == 0)
	{
		if (access(av[ac - 1], W_OK) == -1)
			exit_error("pipex", 1);
	}
	out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out == -1)
		exit_error("Error: cannot open file2", 1);
	return (out);
}

int	open_file_in(int out, char **av)
{
	int	in;

	if (access(av[1], F_OK) == -1)
	{
		close(out);
		exit_error("pipex", 1);
	}
	if (access(av[1], R_OK) == -1)
	{
		close(out);
		exit_error("pipex", 1);
		// ft_printf("pipex: permission denied: %s\n", av[1]);
		// in = open("/dev/null", O_RDONLY);
		// if (in == -1)
		// 	exit_error("Error: cannot open file1", 1);
		// return (in);
	}
	in = open(av[1], O_RDONLY);
	if (in == -1)
	{
		close(out);
		exit_error("Error: cannot open file1", 1);
	}
	return (in);
}

void	setup_here_doc(t_pipex *data, int ac, char **av, char **envp)
{
	data->cmd_count = ac - 4;
	data->cmd = av + 3;
	data->limiteur = av[2];
	data->here_doc = 1;
	data->envp = envp;
	data->fd_transfer = -1;
	data->pidarray = NULL;
	data->in = 0;
	data->out = open_here_out(data->in, ac, av);
	data->pidarray = malloc(sizeof(pid_t) * data->cmd_count);
	if (!data->pidarray)
	{
		close(data->in);
		close(data->out);
		exit_error ("malloc failed", 1);
	}
}

t_pipex	setup_data(int setup, int ac, char **av, char **envp)
{
	t_pipex	data;

	if (setup == 1)
		setup_here_doc(&data, ac, av, envp);
	if (setup == 0)
	{
		data.cmd_count = ac - 3;
		data.cmd = av + 2;
		data.limiteur = NULL;
		data.here_doc = 0;
		data.envp = envp;
		data.fd_transfer = -1;
		data.pidarray = 0;
		data.out = open_file_out(/*data.in, */ac, av);
		data.in = open_file_in(data.out, av);
		data.pidarray = malloc(sizeof(pid_t) * data.cmd_count);
		if (!data.pidarray)
		{
			close(data.in);
			close(data.out);
			exit_error ("malloc failed", 1);
		}
	}
	return (data);
}

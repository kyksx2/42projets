/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:18 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/20 15:05:22 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redir_files(t_p *pipex, int *fd)
{
	dup2(pipex->in, 0);
	close(pipex->in);
	close(pipex->out);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
}

void	close_file(t_p *pipex)
{
	close(pipex->in);
	close(pipex->out);
}

int	open_in(char **av)
{
	int	in;

	if (access(av[1], F_OK) == -1)
		exit_error("pipex", 1);
	if (access(av[1], R_OK) == -1)
	{
		ft_printf("pipex: permission denied: %s\n", av[1]);
		in = open("/dev/null", O_RDONLY);
		if (in == -1)
			exit_error("Error: cannot open file1", 1);
		return (in);
	}
	in = open(av[1], O_RDONLY);
	if (in == -1)
		exit_error("Error: cannot open file1", 1);
	return (in);
}

int	open_out(int in, char **av)
{
	int	out;

	if (access(av[4], F_OK) == 0)
	{
		if (access(av[4], W_OK) == -1)
		{
			close(in);
			exit_error("pipex", 1);
		}
	}
	out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out == -1)
	{
		close(in);
		exit_error("Error: cannot open file2", 1);
	}
	return (out);
}

t_p	setup_pipex(char **av, char **envp)
{
	t_p	data;

	data.envp = envp;
	data.fd_transfer = -1;
	data.in = open_in(av);
	data.out = open_out(data.in, av);
	return (data);
}

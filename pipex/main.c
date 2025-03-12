/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:09:05 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/17 17:09:50 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_execve(char *path, char **args, char **envp)
{
	if (execve(path, args, envp) == -1)
	{
		perror(args[0]);
		free_str(args);
		free(path);
		exit(126);
	}
}

void	exec(char *argv, char **envp)
{
	char	**args;
	char	*path;

	if (!argv)
		return ;
	args = ft_split(argv, ' ');
	if (!args)
		return ;
	if (access(args[0], F_OK) == 0)
		path = args[0];
	else
	{
		path = get_path(args[0], envp);
		if (!path)
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putendl_fd(args[0], 2);
			free_str(args);
			exit(127);
		}
	}
	do_execve(path, args, envp);
}

void	last(t_p *pipex, char *cmd)
{
	pid_t	pid;

	if (!pipex->out)
		return ;
	pid = fork();
	if (pid == -1)
	{
		close_file(pipex);
		exit_error("Error: pipe failed", 1);
	}
	else if (pid == 0)
	{
		dup2(pipex->fd_transfer, 0);
		close(pipex->fd_transfer);
		dup2(pipex->out, 1);
		close(pipex->out);
		exec(cmd, pipex->envp);
	}
	close(pipex->fd_transfer);
	close(pipex->out);
}

void	first(t_p *pipex, char *cmd)
{
	int		fd[2];
	pid_t	pid;

	if (!pipex->in)
		return ;
	if (pipe(fd) == -1)
	{
		close_file(pipex);
		exit_error("Error: pipe failed", 1);
	}
	pid = fork();
	if (pid == -1)
	{
		close_file(pipex);
		exit_error("Error: fork failed", 1);
	}
	else if (pid == 0)
	{
		redir_files(pipex, fd);
		exec(cmd, pipex->envp);
	}
	close(fd[1]);
	close(pipex->in);
	pipex->fd_transfer = fd[0];
}

int	main(int ac, char **av, char **envp)
{
	t_p	pipex;

	if (ac != 5 || !av[2][0] || !av[3][0])
	{
		ft_printf("Error: bad arguments numbers\n");
		return (1);
	}
	pipex = setup_pipex(av, envp);
	first(&pipex, av[2]);
	last(&pipex, av[3]);
	wait(NULL);
	return (0);
}

// void	first(char **argv, char **envp)
// {
// 	pid_t	pid;
// 	int		in_fd;
// 	int		fd[2];

// 	in_fd = open_in(argv[1]);
// 	if(pipe(fd) == -1)
// 		exit_error("Error: pipe failed", 1);
// 	pid = fork();
// 	if (pid == -1)
// 		exit_error("Error: fork failed", 1);
// 	else if (pid == 0)
// 	{
// 		dup2(in_fd, 0);
// 		close(in_fd);
// 		dup2(fd[1], 1);
// 		close(fd[1]);
// 		close(fd[0]);
// 	}
// 	close(in_fd);
// 	close(fd[1]);
// 	dup2(fd[0], 0);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	pid_t	pid;
// 	int		pipefd;
// 	int		fd[2];

// 	if (argc != 5 || !argv[2][0] || !argv[3][0])
// 	{
// 		ft_printf("Error: bad arguments numbers\n");
// 		return (1);
// 	}
// 	else
// 	{
// 		first(argv, envp);
// 		last(argv, envp);
// 		wait(NULL);
// 		return (0);
// 		pipefd = pipe(fd);
// 		if (pipefd == -1)
// 			exit_error("Error: pipe failed", 1);
// 		pid = fork();
// 		if (pid == -1)
// 			exit_error("Error: fork failed", 1);
// 		else if (pid == 0)
// 			child_process(argv, envp, fd);
// 		close(fd[1]);
// 		close(fd[0]);
// 		wait(NULL);
// 		parent_process(argv, envp, fd);
// 		return (0);
// 	}
// }

// void	child_process(char **argv, char **envp, int *fd)
// {
// 	int	child_fd;

// 	if (access(argv[1], F_OK) == -1)
// 	{
// 		dup2(fd[1], 1);
// 		close(fd[1]);
// 		close(fd[0]);
// 		exit_error("pipex", 1);
// 	}
// 	if (access(argv[1], R_OK) == -1)
// 	{
// 		dup2(fd[1], 1);
// 		close(fd[1]);
// 		close(fd[0]);
// 		ft_printf("pipex: permission denied: file1\n");
// 		exit(1);
// 	}
// 	child_fd = open(argv[1], O_RDONLY);
// 	if (child_fd == -1)
// 	{
// 		dup2(fd[1], 1);
// 		close(fd[1]);
// 		close(fd[0]);
// 		exit_error("Error: cannot open file1", 1);
// 	}
// 	dup2(child_fd, 0);
// 	close(child_fd);
// 	dup2(fd[1], 1);
// 	close(fd[1]);
// 	close(fd[0]);
// 	exec(argv[2], envp);
// }

// void	parent_process(char **argv, char **envp, int *fd)
// {
// 	int	parent_fd;

// 	if (access(argv[4], F_OK) == 0)
// 	{
// 		if (access(argv[4], W_OK) == -1)
// 		{
// 			ft_printf("pipex: permission denied: file2\n");
// 			exit(1);
// 		}
// 	}
// 	parent_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (parent_fd == -1)
// 	{
// 		close(fd[0]);
// 		close(fd[1]);
// 		exit_error("Error: cannot open file2", 1);
// 	}
// 	dup2(parent_fd, 1);
// 	close(parent_fd);
// 	dup2(fd[0], 0);
// 	close(fd[0]);
// 	close(fd[1]);
// 	exec(argv[3], envp);
// }
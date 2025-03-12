/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:53:54 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/20 10:27:30 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_execve_bonus(t_pipex *data, char *path, char **args, char **envp)
{
	if (execve(path, args, envp) == -1)
	{
		free(data->pidarray);
		perror(args[0]);
		free_str(args);
		free(path);
		exit(126);
	}
}

void	exec_bonus(t_pipex *data, char *argv, char **envp)
{
	char	**args;
	char	*path;

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
			free(data->pidarray);
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putendl_fd(args[0], 2);
			free_str(args);
			exit(127);
		}
	}
	do_execve_bonus(data, path, args, envp);
}

void	first_check_args(int setup, int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	if (ac < 5 || !av || !envp || (setup == 1 && ac < 6))
	{
		ft_printf("Bad argument\n");
		exit (1);
	}
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_printf("Bad argument\n");
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	int		i;
	int		j;
	int		setup;

	i = 0;
	j = -1;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		setup = 1;
	else
		setup = 0;
	first_check_args(setup, ac, av, envp);
	data = setup_data(setup, ac, av, envp);
	first_cmd(&data, setup);
	while (++i < data.cmd_count - 1)
		rest_cmd(&data, i);
	last_cmd(&data);
	while (++j < data.cmd_count)
		waitpid(data.pidarray[j], NULL, 0);
	close(data.fd_transfer);
	free(data.pidarray);
	return (0);
}

//------------------------------------------------------
// void	call_process(char *argv, char **envp, int file_in)
// {
// 	pid_t	pid;
// 	int		fd[2];

// 	if (pipe(fd) == -1)
// 		exit_error("Error: pipe failed", 1);
// 	pid = fork();
// 	if (pid == -1)
// 		exit_error("Error : fork failed", 1);
// 	else if (pid)
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], 0);
// 		close (fd[0]);
// 		waitpid(pid, NULL, 0);
// 	}
// 	else
// 	{
// 		close (fd[0]);
// 		dup2 (fd[1], 1);
// 		close (fd[1]);
// 		if (file_in == 0)
// 		{
// 			close (file_in);
// 			exit(1);
// 		}
// 		else
// 			exec (argv, envp);
// 	}
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int	file_in;
// 	int	file_out;
// 	int	i;

// 	if (argc < 5)
// 	{
// 		ft_printf("Error: bad arguments numbers");
// 		return (1);
// 	}
// 		file_in = open_file_in(argv[1]);
// 		file_out = open_file_out(argv[argc - 1]);
// 		dup2(file_in, 0);
// 		close(file_in);
// 		dup2(file_out, 1);
// 		close(file_out);
// 		call_process(argv[2], envp, file_in);
// 		i = 2;
// 		while (++i < argc - 2)
// 			call_process(argv[i], envp, -1);
// 		exec(argv[i], envp);
// 		// while (cmd_count)
// 		//	wait;
// 	return (0);
// }
/*

	data{
		.in,
		.out,
		.delimiter,
		.cmd_count,
		.cmd,
		.env
	}

*/

// typedef struct s_data
// {
// 	int in;
// 	int out;
// 	int	messenger;
// 	char *delimiter;
// 	int	cmd_count;
// 	char **cmd;
// 	char **env;
// 	pid_t	*pidarray;
// }	t_data;

// pidarray = mallco(sizoeof(data.cmd_count));

// t_pipex	setup_data(int ac, char **av,  char **env)
// {
// 	t_data data;

// 	data.delimiter = hd_setup();
// 	return ((t_data){
// 		.in = infile_setup(),
// 		.out = infile_setup(),
// 		.delimiter = here_doc_setup(),
// 		.cmd_count = ac - (2  + delimiter != NULL),
// 		.cmd = av + (ac - (2 + delimited != NULL)),
// 		.env = env,
// 	});
// }

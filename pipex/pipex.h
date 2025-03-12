/* ************************************************************************** */
/*		                                                        */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:09:19 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/17 11:32:52 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_p
{
	int		in;
	int		out;
	int		fd_transfer;
	char	**envp;
}	t_p;

/* utils_2 */
t_p		setup_pipex(char **av, char **envp);
int		open_in(char **av);
int		open_out(int in, char **av);
void	close_file(t_p *pipex);
void	redir_files(t_p *pipex, int *fd);
/* utils */
char	*get_path(char *cmd, char **envp);
void	free_str(char **str);
char	*find_path(char **envp);
char	*concat_path(char *new_path, char *cmd);
void	exit_error(char *str, int i);
/* main */
void	exec(char *argv, char **envp);
void	do_execve(char *path, char **args, char **envp);
void	first(t_p *pipex, char *cmd);
void	last(t_p *pipex, char *cmd);
/************************ BONUS PART *************************/

typedef struct s_pipex
{
	int		in;
	int		out;
	int		fd_transfer;
	int		cmd_count;
	int		here_doc;
	char	*limiteur;
	char	**cmd;
	char	**envp;
	pid_t	*pidarray;
}	t_pipex;

void	exec_bonus(t_pipex *data, char *argv, char **envp);
void	do_execve_bonus(t_pipex *data, char *path, char **args, char **envp);
/* utils */
void	close_file_bonus(t_pipex *data);
void	first_check_args(int setup, int ac, char **av, char **envp);
int		open_file_out(int ac, char **av);
int		open_here_out(int in, int ac, char **av);
int		open_file_in(int out, char **av);
t_pipex	setup_data(int setup, int ac, char **av, char **envp);
void	setup_here_doc(t_pipex *data, int ac, char **av, char **envp);
/* cmd */
void	first_cmd_multi_pipe(t_pipex *data);
void	rest_cmd(t_pipex *data, int i);
void	last_cmd(t_pipex *data);
void	first_cmd(t_pipex *data, int setup);
void	first_cmd_here_doc(t_pipex *data);
/* redir */
void	redir_first(t_pipex *data, int *fd);
void	redir_rest(t_pipex *data, int *pipe_fd);
void	redir_last(t_pipex *data);
void	redir_here_doc(t_pipex *data, int *pipe_fd);
/* here_doc */
int		here_cmp(char *line, char *limiteur);
void	here_doc(t_pipex *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:27:32 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/17 13:46:34 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *str, int i)
{
	perror(str);
	exit(i);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*concat_path(char *new_path, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(new_path, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*first_path;
	char	**new_path;
	char	*full_path;

	i = 0;
	first_path = find_path(envp);
	new_path = ft_split(first_path, ':');
	if (!new_path)
		return (NULL);
	while (new_path[i])
	{
		full_path = concat_path(new_path[i], cmd);
		if (!full_path)
			return (free_str(new_path), NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_str(new_path), full_path);
		free(full_path);
		i++;
	}
	free_str(new_path);
	return (NULL);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

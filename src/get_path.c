/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:05:35 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/17 14:19:51 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

char	*get_path(char **env)
{
	int	index;

	index = 0;
	while (env[index] != NULL)
	{
		if (ft_strncmp(env[index], "PATH=", 5) == 0)
			return (env[index] + 5);
		index++;
	}
	return (NULL);
}

char	*get_cmd_without_flags(char *cmd_with_flags)
{
	int		index;
	char	*cmd;

	index = 0;
	while (cmd_with_flags[index] != ' ')
		index++;
	cmd = ft_strndup(cmd_with_flags, index);
	if (!cmd)
		return (NULL);
	return (cmd);
}

char	*get_cmd_path(char *full_path, char *cmd)
{
	char	**paths_2d;
	char	*path;
	int		index;
	char	*cmd_with_slash;

	index = 0;
	paths_2d = ft_split(full_path, ':');
	while (paths_2d[index] != NULL)
	{
		cmd_with_slash = ft_strjoin("/", cmd);
		path = ft_strjoin(paths_2d[index], cmd_with_slash);
		if (path == NULL)
			return (NULL);
		free(cmd_with_slash);
		if (access(path, X_OK) == 0)
		{
			ft_free_2d_array((void **)paths_2d);
			return (path);
		}
		free(path);
		index++;
	}
	ft_free_2d_array((void **)paths_2d);
	// exit_with_error(CMD_N_EXIST);
	// exit(127);
	return (ft_strdup(cmd));
}

int	is_full_path(char *path)
{
	if (path[0] == '/' && access(path, X_OK) == 0)
		return (1);
	return (0);
}

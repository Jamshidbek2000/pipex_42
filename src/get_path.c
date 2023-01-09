/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:05:35 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/09 10:03:19 by jergashe         ###   ########.fr       */
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

char	*get_cmd_path(char *full_path, char *cmd) // "/Users/jergashe/.brew/bin : /Users/jergashe/homebrew/bin:" AND "ls"
{
	char	**paths_2d;
	char	*path;
	int		index;

	index = 0;
	paths_2d = ft_split(full_path, ':'); // [ : ] [ : ]
	while (paths_2d[index] != NULL)
	{
		path = ft_strjoin(paths_2d[index], ft_strjoin("/", cmd)); 
		if (access(path, X_OK) == 0)
		{
			ft_free_2d_array((void **)paths_2d);
			return (path);
		}
		free(path);
		index++;
	}
	ft_putstr_fd("This command doesn't exist in env\n", 1);
	exit(4);
}

int	is_full_path(char *path)
{
	if (path[0] == '/')
		return (1);
	return (0);
}
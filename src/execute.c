/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:59:19 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/07 17:13:23 by jergashe         ###   ########.fr       */
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
			return env[index];
		index++;
	}
	return (NULL);
}

char *copy_n_chars_to_new_allocated_str(char *string, int index_to_start) {
    char *new_str;

	int	len;
	len = ft_strlen(string) - index_to_start + 1;
	new_str = malloc(len);
    if (new_str == NULL)
        return NULL;

    ft_strlcpy(new_str, string + index_to_start, len);

    return new_str;
}

char	*all_path(char *full_path, char *cmd)
{
	char	**all_path;
	char	*path;
	int		index;

	index = 0;
	all_path = ft_split(full_path, ':');
	while (all_path[index] != NULL)
	{
		if (access(all_path[index], X_OK))
			return (all_path[index]);
		path = ft_strjoin(all_path[index], ft_strjoin("/", cmd));
		if (access(path, X_OK))
			return (all_path[index]);
		index++;
	}
	
	
}

void	execute(char *cmd_with_flags, char *env)
{
	char	**cmd_and_flags;

	cmd_and_flags = ft_split(cmd_with_flags, ' ');
	
}

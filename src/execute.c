/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:59:19 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/09 10:20:06 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	execute(char *cmd_with_flags, char **env) // "ls -l -a" OR "/bin/ls"
{
	char	**cmd_2d;
	char	*cmd_path;
	char	*env_var_path;

	cmd_2d = ft_split(cmd_with_flags, ' ');
	if (is_full_path(cmd_2d[0])) // "/bin/ls"
	{
		cmd_path = cmd_2d[0];
		execve(cmd_path, cmd_2d, env);
	}
	else //"ls -l -a"
	{
		env_var_path = get_path(env);
		cmd_path = get_cmd_path(env_var_path, cmd_2d[0]);  // "/Users/jergashe/.brew/bin/ls"
		
		execve(cmd_path, cmd_2d, env);
	}
	ft_free_2d_array((void **)cmd_2d);
}

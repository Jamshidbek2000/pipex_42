/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:59:19 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/17 14:29:09 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	check_cmd(char *cmd_with_flags, char **env);

void	execute(char *cmd_with_flags, char **env)
{
	char	**cmd_2d;
	char	*cmd_path;
	char	*env_var_path;

	cmd_2d = ft_split(cmd_with_flags, ' ');
	if (is_full_path(cmd_2d[0]))
	{
		cmd_path = cmd_2d[0];
		execve(cmd_path, cmd_2d, env);
	}
	else
	{
		// check_cmd(cmd_with_flags, env);
		env_var_path = get_path(env);
		cmd_path = get_cmd_path(env_var_path, cmd_2d[0]);
		// dprintf(2, "PATH %s\n", cmd_path);
		if (execve(cmd_path, cmd_2d, env) == -1)
			exit(ENOENT);
	}
	ft_free_2d_array((void **)cmd_2d);
}

void	check_cmd(char *cmd_with_flags, char **env)
{
	char	*cmd_path;
	char	*cmd;
	char	*error_msg;

	cmd = get_cmd_without_flags(cmd_with_flags);
	cmd_path = get_cmd_path(get_path(env), cmd);
	if (cmd_path == NULL)
	{
		error_msg = ft_strjoin("command not found: ", cmd);
		error_msg = ft_strjoin_free_1(error_msg, "\n");
		// perror(error_msg);
		free(error_msg);
		free(cmd);
		free(cmd_path);
		exit(127);
	}
	free(cmd);
	free(cmd_path);
}

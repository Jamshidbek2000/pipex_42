/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:04:22 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 14:56:02 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	check_cmds(int argc, char **argv, char **env);
void	file_is_readable_check(char *file_name);
void	file_exists_check(char *file_name);
void	nb_of_args_check(int num_of_args);

// check_cmds(argc, argv, env);
int	check_input(int argc, char **argv, char **env)
{
	nb_of_args_check(argc);
	file_exists_check(argv[1]);
	file_is_readable_check(argv[1]);
	return (0);
}

void	nb_of_args_check(int num_of_args)
{
	if (num_of_args < 5)
		exit_with_error(NOT_ENOUGH_ARGS);
}

void	file_exists_check(char *file_name)
{
	if (is_here_doc(file_name))
		return ;
	if (access(file_name, F_OK) == -1)
		exit_with_error(ENOENT);
}

void	file_is_readable_check(char *file_name)
{
	if (is_here_doc(file_name))
		return ;
	if (access(file_name, R_OK) == -1)
		exit_with_error(EACCES);
}

void	check_cmds(int argc, char **argv, char **env)
{
	int		index;
	char	*cmd_path;
	char	*cmd;

	if (is_here_doc(argv[1]))
		index = 3;
	else
		index = 2;
	while (index < argc - 1)
	{
		cmd = get_cmd_without_flags(argv[index]);
		cmd_path = get_cmd_path(get_path(env), cmd);
		if (is_full_path(cmd) || cmd_path != NULL)
		{
			free(cmd);
			free(cmd_path);
			index++;
			continue ;
		}
		free(cmd);
		free(cmd_path);
		exit_with_error(CMD_N_EXIST);
	}
}

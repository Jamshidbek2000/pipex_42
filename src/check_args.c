/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:04:22 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/12 08:59:17 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	check_cmds(int argc, char **argv, char **env);
void	file_is_readable_check(char *file_name);
void	file_exists_check(char *file_name);
void	nb_of_args_check(int num_of_args);

int	check_input(int argc, char **argv, char **env)
{
	nb_of_args_check(argc);
	file_exists_check(argv[1]);
	file_is_readable_check(argv[1]);
	check_cmds(argc, argv, env);
	return (0);
}

void	nb_of_args_check(int num_of_args)
{
	if (num_of_args < 5)
		exit_with_error(NOT_ENOUGH_ARGS);
}

void	file_exists_check(char *file_name)
{
	if (ft_strncmp(file_name, "here_doc", 8) == 0)
		return ;
    if (access(file_name, F_OK) == -1)
		exit_with_error(FILE_N_EXIST);
}

void	file_is_readable_check(char *file_name)
{
	if (ft_strncmp(file_name, "here_doc", 8) == 0)
		return ;
    if (access(file_name, R_OK) == -1)
		exit_with_error(FILE_N_READABLE);
}

void	check_cmds(int argc, char **argv, char **env)
{
	int		index;
	char	*cmd_path;
	char	*cmd;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0) // and len of argv[1] == 8?
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
			continue;
		}
		free(cmd);
		free(cmd_path);
		exit_with_error(CMD_N_EXIST);
	}
}

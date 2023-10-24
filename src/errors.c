/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:53:16 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/03 10:46:37 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	exit_with_error(int error_ind)
{
	if (error_ind == WRONG_INPUT)
		ft_putstr_fd("ERROR: WRONG NUMBER OF ARGC\nENTER 5 ARGS!\n", 2);
	else if (PIPE_ERROR)
		ft_putstr_fd("PIPE FAILED!\n", 2);
	else if (PROCESS_ERROR)
		ft_putstr_fd("PROCESS FAILED!\n", 2);
	exit(error_ind);
}

void	cmd_not_found_exit(char *cmd_with_flags)
{
	char	*cmd;
	char	*error_msg;

	cmd = get_cmd_without_flags(cmd_with_flags);
	error_msg = ft_strjoin("zsh: command not found: ", cmd);
	error_msg = ft_strjoin_free_1(error_msg, "\n");
	perror(error_msg);
	free(error_msg);
	free(cmd);
	exit(127);
}

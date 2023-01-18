/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:47:45 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/18 08:37:44 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

/* O_RDONLY = 0;
O_WRONLY | O_CREAT | O_APPEND = 1;
O_WRONLY | O_CREAT | O_TRUNC = 2; */
int	open_file(char *file_name, int mode, char *cmd)
{
	int		file_fd;
	char	*cmd_only;
	char	*error_msg;

	if (mode == 0)
		file_fd = open(file_name, O_RDONLY, 0644);
	else if (mode == 1)
		file_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (mode == 2)
		file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1) // experiment with wait exit status
	{
		cmd_only = get_cmd_without_flags(cmd);
		error_msg = ft_strjoin_free_1(cmd_only, ": ");
		error_msg = ft_strjoin_free_1(error_msg, file_name);
		perror(error_msg);
		free(error_msg);
		exit(EACCES);
	}
	return (file_fd);
}

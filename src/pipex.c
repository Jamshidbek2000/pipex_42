/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:05:06 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/12 08:59:39 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	child_process(int *pipe_fds, char **argv, char **env)
{
	int	file_fd;

	file_fd = open_file(argv[1], 0);
	close(pipe_fds[0]);
	dup2(file_fd, STDIN_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	execute(argv[2], env);
}

void	parent_process(int *pipe_fds, char **argv, char **env)
{
	int	file_fd;

	file_fd = open_file(argv[4], 2);
	close(pipe_fds[1]);
	dup2(file_fd, STDOUT_FILENO);
	dup2(pipe_fds[0], STDIN_FILENO);
	execute(argv[3], env);
}

void	pipex(char	**argv, char **env)
{
	int	fd[2];
	int	process_id;

	pipe(fd);
	process_id = fork();
	if (process_id == -1)
		return ; // fix
	else if (process_id == 0)
	{
		child_process(fd, argv, env);
	}
	parent_process(fd, argv, env);
}

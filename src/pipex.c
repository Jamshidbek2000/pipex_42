/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:05:06 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/17 14:05:20 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	process_1(int *pipe_fds, char *file_in_name, char *cmd, char **env);
void	process_2(int *pipe_fds, char *file_in_name, char *cmd, char **env);

void	pipex(char	**argv, char **env)
{
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		exit (1);
	process_1(pipe_fds, argv[1], argv[2], env);
	process_2(pipe_fds, argv[4], argv[3], env);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	ft_wait();
}

void	process_1(int *pipe_fds, char *file_in_name, char *cmd, char **env)
{
	pid_t	process_id;
	int		file_in_fd;

	process_id = fork();
	if (process_id == -1)
		exit (2);
	if (process_id == 0)
	{
		close(pipe_fds[0]);
		file_in_fd = open_file(file_in_name, 0, cmd);
		dup2(file_in_fd, STDIN_FILENO);
		close(file_in_fd);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
		// dprintf(2, "1 = %d\n", getpid());
		execute(cmd, env);
	}
}

void	process_2(int *pipe_fds, char *file_out_name, char *cmd, char **env)
{
	pid_t	process_id;
	int		file_out_fd;

	process_id = fork();
	if (process_id == -1)
		exit (2);
	if (process_id == 0)
	{
		close(pipe_fds[1]);
		file_out_fd = open_file(file_out_name, 2, cmd);
		dup2(file_out_fd, STDOUT_FILENO);
		close(file_out_fd);
		dup2(pipe_fds[0], STDIN_FILENO);
		close(pipe_fds[0]);
		// dprintf(2, "2 = %d\n", getpid());
		execute(cmd, env);
		// dprintf(2, "2 = %d\n", getpid());
	}
}
// if (WEFEXITED(status))

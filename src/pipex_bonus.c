/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:21:48 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/19 08:46:52 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	child_process_bonus(char **argv, char **env, int index);
void	last_cmd(char *cmd, char **env, int fd_out);
void	pipex_bonus(int argc, char **argv, char **env);

int	main(int argc, char **argv, char **env)
{
	check_input(argc);
	pipex_bonus(argc, argv, env);
	return (0);
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int	file_fds[2];
	int	index_cmd;
	int	index_last_cmd;

	index_last_cmd = argc - 2;
	file_fds[1] = open_file(argv[argc - 1], 2, argv[argc - 2]);
	index_cmd = 3;
	if (is_here_doc(argv[1]))
		make_here_doc_as_input(argv);
	else
		index_cmd = 2;
	while (index_cmd < index_last_cmd)
		child_process_bonus(argv, env, index_cmd++);
	last_cmd(argv[index_cmd], env, file_fds[1]);
	ft_wait();
}

void	child_process_bonus(char **argv, char **env, int index)
{
	int		fd[2];
	int		process_id;
	char	*cmd;

	cmd = argv[index];
	if (pipe(fd) == -1)
		exit_with_error(PIPE_ERROR);
	process_id = fork();
	if (process_id == -1)
		exit_with_error(PROCESS_ERROR);
	else if (process_id == 0)
	{
		if (is_first_cmd_and_not_here_doc(argv, index) == 1)
			set_file_1_as_stdin(argv, index);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	last_cmd(char *cmd, char **env, int fd_out)
{
	int	process_id;

	process_id = fork();
	if (process_id == -1)
		return ;
	else if (process_id == 0)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		execute(cmd, env);
	}
	else
	{
		close(STDIN_FILENO);
		close(fd_out);
	}
}

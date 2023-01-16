/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:21:48 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 14:06:04 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	child_process_bonus(char *cmd, char **env)
{
	int	fd[2];
	int	process_id;

	if (pipe(fd) == -1)
		return ; // fix
	process_id = fork();
	if (process_id == -1)
		return ; // fix
	else if (process_id == 0)
	{
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
		return ; // fix
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

void	ft_wait()
{
	int	exit_status;
	int	process_id;
	int	status;
	int signal_number;

	process_id = waitpid(0, &status, 0);
	while (process_id != -1)
    {
        if (WIFEXITED(status))
		{
            exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
                printf("Child process with pid: %d terminated with non-zero exit status %d\n", process_id, exit_status);
			else
				printf("Child process with pid: %d terminated with zero exit status %d\n", process_id, exit_status);
        }
		else if (WIFSIGNALED(status))
		{
            signal_number = WTERMSIG(status);
            printf("Child process with pid: %d terminated by signal %d\n", process_id, signal_number);
		}
		process_id = waitpid(0, &status, 0);
	}
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int	file_fds[2];
	int	index_cmd;
	int	index_last_cmd;
	int	exit_status;
	int	process_id;
	int	status;

	index_last_cmd = argc - 2;
	file_fds[1] = open_file(argv[argc - 1], 2);
	if (is_here_doc(argv[1]))
	{	
		make_here_doc_as_input(argv);
		index_cmd = 3;
	}
	else
	{
		file_fds[0] = open_file(argv[1], 0);
		dup2(file_fds[0], STDIN_FILENO);
		close(file_fds[0]);
		index_cmd = 2;
	}

	while (index_cmd < index_last_cmd)
		child_process_bonus(argv[index_cmd++], env);  //./pipex Makefile cat "grep src" "wc -l" out
	last_cmd(argv[index_cmd], env, file_fds[1]);

	ft_wait();
}

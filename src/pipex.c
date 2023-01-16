/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:05:06 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 14:01:53 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	child_process_1(int *pipe_fds, char *file_in_name,char *cmd, char **env)
{
	pid_t	process_id;
	int		file_in_fd;

	process_id = fork();
	if (process_id == -1)
		exit (2);

	if (process_id == 0)
	{
		file_in_fd = open_file(file_in_name, 0);
		close(pipe_fds[0]); // slose read
		
		dup2(file_in_fd, STDIN_FILENO);
		close(file_in_fd);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]); // close write
		
		execute(cmd, env);
	}
}

void	child_process_2(int *pipe_fds, char *file_out_name, char *cmd, char **env)
{
	pid_t	process_id;
	int		file_out_fd;

	process_id = fork();
	if (process_id == -1)
		exit (2);

	if (process_id == 0)
	{
		close(pipe_fds[1]); // close write
		file_out_fd = open_file(file_out_name, 2);
		
		dup2(file_out_fd, STDOUT_FILENO);
		close(file_out_fd);
		dup2(pipe_fds[0], STDIN_FILENO);
		close(pipe_fds[0]); // close read
		
		execute(cmd, env);
	}
}

void	pipex(char	**argv, char **env)
{
	int		pipe_fds[2];
	int		status;
	int		exit_status;
	int		process_id;

	if (pipe(pipe_fds) == -1)
		exit (1);
	

	child_process_1(pipe_fds, argv[1], argv[2], env);
	child_process_2(pipe_fds, argv[4], argv[3], env);
	
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	
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
            int signal_number = WTERMSIG(status);
            printf("Child process with pid: %d terminated by signal %d\n", process_id, signal_number);
		}
		process_id = waitpid(0, &status, 0);
	}
}


// if (WEFEXITED(status))
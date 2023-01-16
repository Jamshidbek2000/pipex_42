/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_old.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:05:06 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/15 12:00:40 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	child_process_2(int *pipe_fds, int	*file_fds, char *cmd, char **env)
{
	pid_t	process_id;

	printf("ENTERED PROCESS 2\n");
	process_id = fork();
	if (process_id == -1)
		exit (2);

	if (process_id == 0)
	{
		close(pipe_fds[0]); // slose read
		
		dup2(file_fds[0], STDIN_FILENO);
		dup2(pipe_fds[1], STDOUT_FILENO);
		
		close(pipe_fds[1]); // close write
		
		close(file_fds[0]); // close input file
		close(file_fds[1]); // close input file
		
		execute(cmd, env);
	}
}

void	child_process_3(int *pipe_fds, int	*file_fds, char *cmd, char **env)
{
	pid_t	process_id;

	printf("ENTERED PROCESS 3\n");
	process_id = fork();
	if (process_id == -1)
		exit (2);

	if (process_id == 0)
	{
		close(pipe_fds[1]); // close write
		
		dup2(pipe_fds[0], STDIN_FILENO);
		dup2(file_fds[1], STDOUT_FILENO);
		
		close(pipe_fds[0]); // close read
		
		close(file_fds[1]); // close write file
		close(file_fds[0]); // close write file
		
		execute(cmd, env);
	}
}

void	pipex(char	**argv, char **env)
{
	int		pipe_fds[2];
	int		file_fds[2];

	printf("ENTERED PIPEX\n");
	if (pipe(pipe_fds) == -1)
		exit (1);
	
	file_fds[0] = open_file(argv[1], 0);
	file_fds[1] = open_file(argv[4], 2);

	child_process_2(pipe_fds, file_fds, argv[2], env);
	child_process_3(pipe_fds, file_fds, argv[3], env);
	printf("EXITED PROCESSES\n");
	
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	
	close(file_fds[0]);
	close(file_fds[1]);
	
	while (wait(NULL) != -1) ;
	printf("AFTER WAIT\n");
}


void	child_process(int *pipe_fds, char **argv, char **env)
{
	int	file_fd;

	file_fd = open_file(argv[1], 0);
	close(pipe_fds[0]);
	dup2(file_fd, STDIN_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	// close(pipe_fds[1]);
	execute(argv[2], env);
}

void	parent_process(int *pipe_fds, char **argv, char **env)
{
	int	file_fd;
	int status;
	
	file_fd = open_file(argv[4], 2);
	close(pipe_fds[1]);
	dup2(file_fd, STDOUT_FILENO);
	dup2(pipe_fds[0], STDIN_FILENO);
	execute(argv[3], env);
	// wait(&status);
	// if (WIFEXITED(status))
		
	// if (WIFSIGNALED(status))
		
}

// void	pipex(char	**argv, char **env)
// {
// 	int	fd[2];
// 	pid_t	process_id;

// 	pipe(fd); // check
// 	process_id = fork();
// 	if (process_id == -1)
// 		return ; // fix
// 	else if (process_id == 0)
// 	{
// 		child_process(fd, argv, env);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 	}
// 	parent_process(fd, argv, env);
// }
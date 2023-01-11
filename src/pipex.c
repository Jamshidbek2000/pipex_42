/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:05:06 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/11 11:46:27 by jergashe         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	check_input(argc, argv, env);

	pipex(argv, env);

	// pipex_bonus(argc, argv, env);
	printf("-- END --\n");
	return (0);
}


// cases:
// cat /dev/urandom | head -10   // infile "cat /dev/urandom" "head -10"
// cat | cat | ls
//  fd - 2 for errors
// infile sleep 10 ls outfile 
// outfile to be created

// ./pipex in "sleep 100" "sleep 10000" out 

// ./pipex here_doc stop_word cat cat cat cat out_file
// ./pipex here_doc stop_word cat cat cat cat out_file
// ./pipex file_name cmd cmd cmd file2_name
 // echo $?
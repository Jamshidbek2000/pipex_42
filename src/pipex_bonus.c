/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:21:48 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/12 14:36:49 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	execute_here_doc(char *stop_word, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, stop_word, ft_strlen(stop_word)) == 0 &&
			ft_strlen(line) - 1 == ft_strlen(stop_word))
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	make_here_doc_as_input(char **argv)
{
	int	fd[2];
	int	process_id;

	if (pipe(fd) == -1)
		exit_with_error(PIPE_ERROR); // fix
	process_id = fork();
	if (process_id == -1)
		exit(PROCESS_ERROR); // fix
	else if (process_id == 0)
	{
		execute_here_doc(argv[2], fd); 
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(process_id, NULL, 0);
	}
}

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
		execute(cmd, env);
	}
	else
	{
		// waitpid(process_id, NULL, 0);
		// strerror(status);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO); 
	}
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int	fd[2];
	int	arg_index;

	pipe(fd);
	// identify what is going to be STDIN
	fd[1] = open_file(argv[argc - 1], 2);
	if (is_here_doc(argv[1])) // here_doc
	{	
		make_here_doc_as_input(argv);
		arg_index = 3;
	}
	else // or file_1
	{
		fd[0] = open_file(argv[1], 0);
		dup2(fd[0], STDIN_FILENO);
		arg_index = 2;
	}
	while (arg_index < argc - 2)
	{
		child_process_bonus(argv[arg_index++], env);  //./pipex Makefile cat "grep src" "wc -l" out
	}
	while (arg_index-- > 0)
	{
		printf("WAITING\n");
		waitpid(-1, NULL, 0);
	}
	dup2(fd[1], STDOUT_FILENO);
	execute(argv[argc - 2], env);
}

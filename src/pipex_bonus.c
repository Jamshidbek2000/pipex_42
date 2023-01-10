/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:21:48 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/10 11:26:57 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	make_here_doc_as_input()
{
	int	fd[2];
	int	process_id;

	if (pipe(fd) == -1)
		exit(6); // fix
	process_id = fork();
	if (process_id == -1)
		exit(6); // fix
	else if (process_id == 0)
	{
		// execute_here_doc(); 
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(process_id, NULL, 0);
	}
}


void	execute_here_doc(char *stop_word, int *fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, stop_word, ft_strlen(stop_word)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
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
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(process_id, NULL, 0);
	}
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int	fd[2];
	int	arg_index;

	pipe(fd);
	// identify what is going to be STDIN
	if (ft_strncmp(argv[1], "here_doc", 8) == 0) // here_doc
	{
		
		make_here_doc_as_input(argv[2], fd);
		arg_index = 3;
	}
	else // or file_1
	{
		fd[0] = open_file(argv[1], 0);
		fd[1] = open_file(argv[argc - 1], 2);
		dup2(fd[0], STDIN_FILENO);
		arg_index = 2;
	}
	while (arg_index < argc - 2)
	{
		child_process_bonus(argv[arg_index++], env);  //./pipex Makefile cat "grep src" "wc -l" out
	}
	dup2(fd[1], STDOUT_FILENO);
	execute(argv[argc - 2], env);
}

// int	main(int argc, char **argv, char **env)
// {
	
// 	return (0);
// }

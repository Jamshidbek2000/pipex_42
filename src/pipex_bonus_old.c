/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_old.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:37:33 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 08:37:37 by jergashe         ###   ########.fr       */
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
		close(fd_out);
	}
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int	fd[2];
	int	arg_index;
	int temp_fd;

	fd[1] = open_file(argv[argc - 1], 2);
	temp_fd = dup(0);
	if (is_here_doc(argv[1]))
	{	
		make_here_doc_as_input(argv);
		arg_index = 3;
	}
	else
	{
		fd[0] = open_file(argv[1], 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		arg_index = 2;
	}

	while (arg_index < argc - 2)
		child_process_bonus(argv[arg_index++], env);  //./pipex Makefile cat "grep src" "wc -l" out

	last_cmd(argv[arg_index], env, fd[1]);

	dup2(temp_fd, 0);
	while (wait(NULL) > 0);

}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:56:35 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/19 08:20:00 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	ft_wait(void)
{
	int	process_id;
	int	status;

	process_id = waitpid(0, &status, 0);
	while (process_id != -1)
		process_id = waitpid(0, &status, 0);
}

void	set_file_1_as_stdin(char **argv, int index)
{
	int		file_in_fd;
	char	*cmd;
	char	*file_name;

	file_name = argv[1];
	cmd = argv[index];
	file_in_fd = open_file(file_name, 0, argv[index]);
	dup2(file_in_fd, STDIN_FILENO);
	close(file_in_fd);
}

void	check(void)
{
	system("leaks pipex");
}

// void	ft_wait(void)
// {
// 	int	exit_status;
// 	int	process_id;
// 	int	status;
// 	int	signal_number;

// 	process_id = waitpid(0, &status, 0);
// 	dprintf(2 ,
// 		"\t\tPROCESS WITH ID %d EXITED\n", process_id);
// 	while (process_id != -1)
// 	{
// 		if (WIFEXITED(status))
// 		{
// 			exit_status = WEXITSTATUS(status);
// 			if (exit_status != 0 && exit_status > 106)
// 				dprintf(2, "My error: %s with exit status %d\n",
// 				strerror(exit_status), exit_status);
// 			else
// 				printf("Child process with pid: %d 
// 				terminated with zero exit status %d\n",
// 				process_id, exit_status);
// 		}
// 		else if (WIFSIGNALED(status))
// 		{
// 			signal_number = WTERMSIG(status);
// 			printf("Child process with pid: %d 
// 			terminated by signal %d\n",
// 			process_id, signal_number);
// 		}
// 		process_id = waitpid(0, &status, 0);
// 		dprintf(2 ,"\t\tPROCESS WITH ID %d EXITED\n", process_id);
// 	}
// }
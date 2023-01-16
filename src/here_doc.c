/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:34:50 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 08:36:31 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

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
		close(fd[0]);
		waitpid(process_id, NULL, 0);
	}
}

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

// Function returns 1 if input is here_doc
// if no returns 0
int	is_here_doc(char *input)
{
	if (ft_strncmp(input, "here_doc", 8) == 0
		&& ft_strlen(input) == 8)
		return (1);
	return (0);
}

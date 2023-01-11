/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:47:45 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/11 13:52:53 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

/* O_RDONLY = 0;
O_WRONLY | O_CREAT | O_APPEND = 1;
O_WRONLY | O_CREAT | O_TRUNC = 2; */
 int	open_file(char *filename, int mode)
{
	int	file_fd;

	if (mode == 0)
		file_fd = open(filename, O_RDONLY, 0644);
	else if (mode == 1)
		file_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (mode == 2)
		file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
	{
		perror("Exited due to error when openning the file\n");
		exit(5);
	}
	return (file_fd);
}

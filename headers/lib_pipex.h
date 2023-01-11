/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:06:24 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/11 11:41:58 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# include "../libft_42/libft.h"
# include "../get_next_line_42/get_next_line.h"

# define FILE_N_EXIST 1
# define FILE_N_READABLE 2
# define NOT_ENOUGH_ARGS 3
# define CMD_N_EXIST 4
# define PATH_N_EXIST 5

char	*get_path(char **env);
char	*get_cmd_path(char *full_path, char *cmd);
void	execute(char *cmd_with_flags, char **env);

int		check_input(int argc, char **argv, char **env);

int		is_full_path(char *path);

int		open_file(char *filename, int mode);

void	exit_with_error(int	error_ind);

void	pipex_bonus(int argc, char **argv, char **env);

char	*get_cmd_without_flags(char *cmd_with_flags);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:06:24 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 11:18:46 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

# include <stdio.h>

# include "../libft_42/libft.h"
# include "../get_next_line_42/get_next_line.h"

# define NOT_ENOUGH_ARGS 107
# define CMD_N_EXIST 127
# define NOT_ENOUGH_ARGS2 6
# define PIPE_ERROR 7
# define PROCESS_ERROR 7

char	*get_path(char **env);
char	*get_cmd_path(char *full_path, char *cmd);

void	execute(char *cmd_with_flags, char **env);

int		check_input(int argc, char **argv, char **env);

int		is_full_path(char *path);

int		open_file(char *filename, int mode);

void	exit_with_error(int	error_ind);

void	pipex(char **argv, char **env);
void	pipex_bonus(int argc, char **argv, char **env);

char	*get_cmd_without_flags(char *cmd_with_flags);

void	make_here_doc_as_input(char **argv);
void	execute_here_doc(char *stop_word, int *fd);
int		is_here_doc(char *input);

void	check();

#endif
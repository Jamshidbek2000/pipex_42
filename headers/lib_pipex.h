/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:06:24 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/18 10:41:26 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# include <stdio.h>

# include "../libft_42/libft.h"
# include "../get_next_line_42/get_next_line.h"

# define NOT_ENOUGH_ARGS 107
# define PIPE_ERROR 108
# define PROCESS_ERROR 109

void	pipex(char **argv, char **env);
void	pipex_bonus(int argc, char **argv, char **env);

void	check_input(int argc, char **argv, char **env);
void	check(void);

void	exit_with_error(int	error_ind);
void	cmd_not_found_exit(char *cmd_with_flags);

char	*get_path(char **env);
char	*get_cmd_path(char *full_path, char *cmd);
char	*get_cmd_without_flags(char *cmd_with_flags);
int		is_full_path(char *path);

void	execute(char *cmd_with_flags, char **env);

int		open_file(char *file_name, int mode, char *cmd);

void	make_here_doc_as_input(char **argv);
void	execute_here_doc(char *stop_word, int *fd);
int		is_here_doc(char *input);

void	ft_wait(void);
int		is_first_cmd_and_not_here_doc(char **argv, int index);
int		set_file_1_as_stdin(char **argv, int index);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:06:24 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/09 17:04:16 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# include "../libft_42/libft.h"

char	*get_path(char **env);
char	*get_cmd_path(char *full_path, char *cmd);
void	execute(char *cmd_with_flags, char **env);

int		check_input(int argc, char **argv, char **env);

int		is_full_path(char *path);

int		open_file(char *filename, int mode);

void	pipex_bonus(int argc, char **argv, char **env);



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:53:16 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/11 10:27:06 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	exit_with_error(int	error_ind)
{
	if (error_ind == FILE_N_EXIST)
		ft_putstr_fd("ERROR: FILE DOES NOT EXIST!\n", 2);
	else if (error_ind == FILE_N_READABLE)
		ft_putstr_fd("ERROR: FILE IS NOT READABLE!\n", 1);
	else if (error_ind == NOT_ENOUGH_ARGS)
		ft_putstr_fd("ERROR: NOT ENOUGH ARGS\nENTER AT LEAST 4 ARGS!", 1);
	else if (error_ind == CMD_N_EXIST)
		ft_putstr_fd("ERROR: CMD DOES NOT EXIST OR NOT ACCESSIBLE!\n", 1);
	else if (error_ind == PATH_N_EXIST)
		ft_putstr_fd("ERROR: PATH DOES NOT EXIST!\n", 1);
	exit(error_ind);
}

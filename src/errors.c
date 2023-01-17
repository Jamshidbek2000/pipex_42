/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:53:16 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/17 14:00:19 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	exit_with_error(int error_ind)
{
	if (error_ind == ENOENT) // NEEDED???
		ft_putstr_fd("ERROR: NO SUCH FILE OR DIRECTORY!\n", 2);
	else if (error_ind == NOT_ENOUGH_ARGS)
		ft_putstr_fd("ERROR: NOT ENOUGH ARGS\nENTER AT LEAST 4 ARGS!", 2);
	else if (error_ind == CMD_N_EXIST)
		ft_putstr_fd("ERROR: CMD DOES NOT EXIST OR NOT ACCESSIBLE!\n", 2);
	exit(error_ind);
}

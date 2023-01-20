/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:04:22 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/20 08:14:05 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	nb_of_args_check(int num_of_args);

void	check_input(int argc)
{
	nb_of_args_check(argc);
}

void	nb_of_args_check(int num_of_args)
{
	if (num_of_args < 5)
		exit_with_error(WRONG_INPUT);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:04:22 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/08 15:04:41 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	nb_of_args_check(int num_of_args)
{
	if (num_of_args < 5)
	{
	ft_putstr_fd("Wrong input!\nExample:\n", 1);
	ft_putstr_fd("file_1 cat \"grep main\" file_2\n", 1);
	ft_putstr_fd("Enter at least 3 arguments\n", 1);
	exit(1);
	}
}

void	file_exists_check(char *file_name)
{
    if (access(file_name, F_OK) == -1)
    {
		ft_putstr_fd("Wrong input!\n", 1);
		ft_putstr_fd("File does not exist\n", 1);
        exit(2);
    }
}

void	file_is_readable_check(char *file_name)
{
    if (access(file_name, R_OK) == -1)
    {
		ft_putstr_fd("Wrong input!\n", 1);
        ft_putstr_fd("File is not readable!\n", 1);
		exit(3);
    }
}

int	check_input(int argc, char **argv, char **env)
{
	nb_of_args_check(argc);
	file_exists_check(argv[1]);
	file_is_readable_check(argv[1]);
	
	return (0);
}

void	check()
{
	system("leaks pipex");
}

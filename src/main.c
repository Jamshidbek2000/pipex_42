/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:59:45 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/18 10:50:50 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

int	main(int argc, char **argv, char **env)
{
	check_input(argc, argv, env);
	// pipex(argv, env);
	pipex_bonus(argc, argv, env);
	// while (1) ;
	atexit(check);
	printf("-- END --\n");
	return (0);
}

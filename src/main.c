/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:59:45 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 14:58:04 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

int	main(int argc, char **argv, char **env)
{
	check_input(argc, argv, env);
	pipex(argv, env);
	// pipex_bonus(argc, argv, env);
	// while (1) ;
	// atexit(check);
	printf("-- END --\n");
	return (0);
}

// cases:
// cat /dev/urandom | head -10   // infile "cat /dev/urandom" "head -10"
// cat | cat | ls
//  fd - 2 for errors
// infile sleep 10 ls outfile 
// outfile to be created
// ./pipex in "sleep 100" "sleep 10000" out 
// ./pipex here_doc stop_word cat cat cat cat out_file
// ./pipex file_name cmd cmd cmd file2_name
// echo $?
// can I use lib bash.h to get error values?
// shoudl the last cmd exit in execve or main: return(0)?
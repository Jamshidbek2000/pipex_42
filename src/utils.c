/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:56:35 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/12 08:59:20 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

// Function returns 1 if input is here_doc
// if no returns 0
int	is_here_doc(char *input)
{
	if (ft_strncmp(input, "here_doc", 8) == 0
		&& ft_strlen(input) == 8)
		return (1);
	return (0);
}

void	check()
{
	system("leaks pipex");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:45:00 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/09 15:35:16 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Receives the path from main and initialises the program
** Returns 1 on failure and 0 on success
*/

int		launch_fillit(int ac, char **av)
{
	char	*str_data;
	char	**table_tetri;

	str_data = NULL;
	// MOVE THIS TO MAIN FOR CLARITY
	if (ac != 2)
	{
		ft_putendl_fd("usage: fillit tetriminos_file", 2);
		return (2);
	}
	str_data = open_close_file(av[1]);
	if (!(str_data))
		return (1);
	//str_data = check_input(str_data);
	table_tetri = check_tetriminos(str_data);
	return (0);
}

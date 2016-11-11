/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:45:00 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 09:22:47 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Receives the path from main and initialises the program
** Returns 1 on failure and 0 on success
*/
#include <stdio.h>

int		launch_fillit(char **av)
{
	char	*str_data;
	char	**table_tetri;

	str_data = NULL;
	table_tetri = NULL;
	str_data = open_close_file(av[1]);
	if (!(str_data))
		return (1);
	str_data = check_input(str_data);
	if (!str_data)
		return (1);
	table_tetri = check_tetriminos(str_data);
	int i = 0;
	while (table_tetri[i])
	{
		ft_putnbr(i);
		ft_putstr(table_tetri[i]);
		i++;
	}
	if (compare_tetris(table_tetri))
		return (1);
	return (0);
}

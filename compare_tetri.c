/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:49:25 by sycohen           #+#    #+#             */
/*   Updated: 2016/11/10 18:08:56 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <stdio.h>

int		compare_tetris(char **tetris)
{
	int		i;
	int		j;
	int		count;
	char	**tetri;

	i = 0;
	count = 0; 
	tetri = NULL;
	tetri = malloc(150);
	tetri[0] = strdup("1#\n#\n#\n#\n####\n2#.\n#.\n##\n2..#\n###\n2##\n.#\n.#\n2###\n#..\n");
	tetri[1] = strdup("3.#.\n###\n3.#\n##\n.#\n3###\n.#.\n3#.\n##\n#.\n");
	tetri[2] = strdup("4.#\n.#\n##\n4.###\n..#\n4##\n#.\n#.\n4#..\n###\n");
	tetri[3] = strdup("5##\n##\n6##.\n.##\n6.#\n##\n#.\n7.##\n##.\n7#.\n##\n.#\n");
	while(tetris[i])
	{
		j = 0;
		while (j < 4)
		{
			if (ft_strstr(tetri[j], tetris[i]))
				count++;
			j++;
		}
		i++;
	}
	printf("count %d\n", count);
	printf("i %d\n", i);

	return (0);
}

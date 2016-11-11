/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:49:25 by sycohen           #+#    #+#             */
/*   Updated: 2016/11/11 15:35:06 by sycohen          ###   ########.fr       */
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
	char	**t;

	i = 0;
	count = 0;
	if (!(t = ft_memalloc(sizeof(char*) * 6)))
		return (1);
	t[0] = ft_strdup("1#\n#\n#\n#\n1####\n");
	t[1] = ft_strdup("2#.\n#.\n##\n2..#\n###\n2##\n.#\n.#\n2###\n#..\n");
	t[2] = ft_strdup("3.#.\n###\n3.#\n##\n.#\n3###\n.#.\n3#.\n##\n#.\n");
	t[3] = ft_strdup("4.#\n.#\n##\n4.###\n..#\n4##\n#.\n#.\n4#..\n###\n");
	t[4] = ft_strdup("5##\n##\n6##.\n.##\n6.#\n##\n#.\n7.##\n##.\n7#.\n##\n.#\n");
	while (tetris[i])
	{
		j = 0;
		while (j < 5)
			if (ft_strstr(t[j++], tetris[i]))
				count++;
		i++;
	}
	free(t);
	return (count == i ? 0 : 1);
}

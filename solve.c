/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:15:08 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 11:47:28 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*typedef	struct	s_coord
{
	int		x;
	int		y;
}				t_coord;*/

int		is_fit(char **tetri, char **to_fill, int i_tetri, int x, int y)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (to_fill[y + i][x + j] == '.' && tetri[i][j] == '#')
			{
			   	to_fill[y + i][x + j] = 'A' + i_tetri;
				count++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**create_table(int size)
{
	char	**to_fill;
	int		i;

	i = 0;
	if ((to_fill = (char **)malloc(sizeof(char *) * size + 1)) == NULL)
		return (NULL);
	while (i < size)
	{
		to_fill[i] = ft_strnew(size + 1);
		ft_memset(to_fill[i++], '.', size);
	}
	to_fill[i] = NULL;
	return (to_fill);
}

/*char	**try_table(char **to_fill, char ***tetri_table, int i_tetri)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y != 0)
	{
		x = 0;
		while (x != 0)
		{
			if (is_fit(tetri_table[i_tetri], to_fill, k))
				return (try_table(to_fill, tetri_table, i_tetri++));
			else
				delete_trace_tetri(to_fill, tetri_table, i_tetri);
			x++;
		}
		y++;
	}
	return (NULL);
}*/

int		list_len(char ***list_tetri)
{
	int i;
	
	i = 0;
	while (list_tetri[i])
		i++;
	return (i);
}

int		solve(char	***list_tetri)
{
	int		i;
	char	**filled;

	i = 2;
	filled = NULL;
	while (ft_iterative_power(i, 2) < (list_len(list_tetri) * 4))
		i++;
	/*while (!(filled = try_table(create_table(i), list_tetri, 0)))
	{ 
		free(to_fill);
		i++;
	}*/
	filled = create_table(i);
	is_fit(list_tetri[1], filled, 1, 0, 0);
	display_table(filled);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:15:08 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/10 17:31:15 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

typedef	struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

int		is_fit(char **tetri, char **to_fill, int i_tetri, t_coord xy)
{
	int		i;
	int		j;

	i = 0;
	while (to_fill[xy.y + i])
	{
		j = 0;
		while (to_fill[xy.y + i][xy.x + j])
		{
			//GERER TOUS LES CAS D'ERREURS TYPE: # et #, DEPASSEMENT TABLEAU.
			//IL FAUT RETURN 1 UNIQUEMENT SI 4 # ONT ETE PLACES, SINON 0.
			if (to_fill[xy.y + i][xy.x + j] != '#' && tetri[i][j] == '#')
			   	to_fill[xy.y + i][xy.x + j] = 'A' + k;
		}
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
		ft_memset(to_fill[i++], '.', size + 1);
	}
	to_fill[i] = '\0';
	return (to_fill);
}

char	**try_table(char **to_fill, char ***tetri_table, int i_tetri)
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
}

int		solve(char	***tetri_table)
{
	int		i;
	char	**filled;

	i = 2;
	filled = NULL;
	while (ft_iterative_power(i) < (table_len * 4))
		i++;
	while (filled = try_table(create_table(i), tetri_table, 0))
	{ 
		free(to_fill);
		i++;
	}
	display(filled);
}

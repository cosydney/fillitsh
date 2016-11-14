/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:15:08 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/12 14:39:21 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		is_fit(char **tetri, char **to_fill, int i_tetri, t_coord axis)
{
	int	i;
	int	j;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (!to_fill[axis.y + i])
				return (0);
			if (to_fill[axis.y + i][axis.x + j] != '.' && tetri[i][j] == '#')
				return (0);
			else if (tetri[i][j] == '#')
				to_fill[axis.y + i][axis.x + j] = 'A' + i_tetri;
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

void	delete_trace_tetri(char **to_fill, int i_tetri)
{
	int		i;
	int		j;

	i = 0;
	while (to_fill[i])
	{
		j = 0;
		while (to_fill[i][j])
		{
			if (to_fill[i][j] == 'A' + i_tetri)
				to_fill[i][j] = '.';
			j++;
		}
		i++;
	}
}

char	**try_table(char **to_fill, char ***tetri_table, int i_tetri)
{
	t_coord axis;
	char	**test;

	axis.x = 0;
	axis.y = 0;
	while (to_fill[axis.y])
	{
		axis.x = 0;
		while (to_fill[axis.y][axis.x])
		{
			if (is_fit(tetri_table[i_tetri], to_fill, i_tetri, axis))
			{
				if (tetri_table[i_tetri + 1] == NULL)
					return (to_fill);
				if ((test = try_table(to_fill, tetri_table, i_tetri + 1)))
					return (test);
			}
			delete_trace_tetri(to_fill, i_tetri);
			axis.x++;
		}
		axis.y++;
	}
	return (NULL);
}

int		solve(char ***list_tetri)
{
	int		i;
	char	**filled;

	i = 2;
	filled = NULL;
	while (ft_iterative_power(i, 2) < (list_len(list_tetri) * 4))
		i++;
	filled = create_table(i);
	while (!(filled = try_table(filled, list_tetri, 0)))
	{
		free(filled);
		i++;
		filled = create_table(i);
	}
	display_table(filled);
	free(filled);
	return (0);
}

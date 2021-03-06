/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:20:39 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 20:10:39 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*copy_trim(char **indiv_tetri)
{
	char	*trim_cpy;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if ((trim_cpy = (char *)malloc(sizeof(char) * 9)) == NULL)
		return (NULL);
	while (indiv_tetri[i])
	{
		j = 0;
		while (indiv_tetri[i][j])
		{
			if (indiv_tetri[i][j] != '-')
				trim_cpy[k++] = indiv_tetri[i][j];
			j++;
		}
		i++;
	}
	trim_cpy[k] = '\0';
	return (trim_cpy);
}

void	trim_col(char **indiv_tetri, int col)
{
	int		i;

	i = 0;
	while (i < 4)
		if (indiv_tetri[i++][col] == '#')
			return ;
	while (i < 8)
		indiv_tetri[i++ % 4][col] = '-';
}

void	trim_row(char *tetri_row)
{
	int		i;

	i = 0;
	while (i < 5)
		if (tetri_row[i++] == '#')
			return ;
	while (i < 10)
		tetri_row[i++ % 5] = '-';
}

int		check_proximity(char **tetri, int i, int j, int count)
{
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (i < 3)
				if (tetri[i][j] == '#' && tetri[i + 1][j] == '#')
					count++;
			if (i <= 3)
				if (tetri[i][j] == '#' && tetri[i][j + 1] == '#')
					count++;
			j++;
		}
		if (i == 3)
		{
			if (count != 3 && count != 4)
				return (1);
			count = 0;
		}
		i++;
	}
	return (0);
}

char	*remove_edges(char **indiv_tetri)
{
	int		i;
	char	*trim_cpy;

	i = 0;
	trim_cpy = NULL;
	if (check_proximity(indiv_tetri, 0, 0, 0))
		return (NULL);
	while (i < 4)
		trim_row(indiv_tetri[i++]);
	while (i < 8)
		trim_col(indiv_tetri, (i++ % 4));
	trim_cpy = copy_trim(indiv_tetri);
	return (trim_cpy);
}

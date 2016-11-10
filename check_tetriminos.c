/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:13:42 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/10 11:42:11 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


// THIS FILE NEEDS TO BE SPLIT IN DIFFERENT FILES FOR CLARITY


void	trim_col(char **indiv_tetri, int col)
{
	int		i;

	i = 0;
	while (i < 4)
		if (indiv_tetri[i++][col] == '#')
			return (NULL);
	while (i < 8)
		indiv_tetri[i++ % 4][col] = '-';
	return (indiv_tetri);
}

void	trim_row(char *tetri_row)
{
	int 	i;

	i = 0;
	while (i < 5)
		if (tetri_row[i++] == '#')
			return (NULL);
	while (i < 10)
		tetri_row[i++ % 5] = '-';
	return (tetri_row);
}

char	*remove_edges(char **indiv_tetri)
{
	int		i;

	i = 0;
	while (i < 4)
		check_row(indiv_tetri[i++]);
	while (i < 8)
		check_col(indiv_tetri, (i++ % 4));
	while (i < 12)
		ft_putstr(indiv_tetri[i++ % 4]);
	return (*indiv_tetri);
}

char	**split_tetri(char *str_data)
{
	char	**table_tetri;
	char	**indiv_tetri;
	int		i;
	int		j;

	j = 0;
	table_tetri = (char **)malloc(sizeof(char *) * (ft_strlen(str_data) % 20 + 2));
	if (!table_tetri)
		return (NULL);
	while (*str_data)
	{
		if (*str_data == '\n')
			str_data++;
		i = 0;
		if ((indiv_tetri = (char **)malloc(sizeof(char *) * 5)) == NULL)
			return (NULL);
		while (i < 4)
		{
			indiv_tetri[i++] = ft_strndup(str_data, 5);
			str_data += 5;
		}
		indiv_tetri[i] = NULL;
		table_tetri[j++] = remove_edges(indiv_tetri);
		free(indiv_tetri);
	}
	return (table_tetri);
}

char	**check_tetriminos(char *str_data)
{
	char	**table_tetri;

	table_tetri = NULL;
	table_tetri = split_tetri(str_data);
	if (!table_tetri)
		return (NULL);
	return (table_tetri);
}

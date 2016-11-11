/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:13:42 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 20:10:37 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**split_tetri(char *str, int i, int j)
{
	char	**table_tetri;
	char	**indiv_tetri;

	table_tetri = (char **)malloc(sizeof(char *) * (ft_strlen(str) / 20 + 2));
	if (!table_tetri)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			str++;
		i = 0;
		if ((indiv_tetri = (char **)malloc(sizeof(char *) * 5)) == NULL)
			return (NULL);
		while (i < 4)
		{
			indiv_tetri[i++] = ft_strndup(str, 5);
			str += 5;
		}
		indiv_tetri[i] = NULL;
		if ((table_tetri[j++] = remove_edges(indiv_tetri)) == NULL)
			return (NULL);
		free(indiv_tetri);
	}
	table_tetri[j] = NULL;
	return (table_tetri);
}

char	**check_tetriminos(char *str)
{
	char	**table_tetri;

	table_tetri = NULL;
	if ((table_tetri = split_tetri(str, 0, 0)) == NULL)
		return (NULL);
	if (!table_tetri)
		return (NULL);
	return (table_tetri);
}

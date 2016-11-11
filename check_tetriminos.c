/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:13:42 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 08:45:52 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**split_tetri(char *str_data)
{
	char	**table_tetri;
	char	**indiv_tetri;
	int		i;
	int		j;

	j = 0;
	ft_putnbr(ft_strlen(str_data) % 20 + 2);
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
	table_tetri[j] = '\0';
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

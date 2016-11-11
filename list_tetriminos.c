/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 08:55:30 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 11:12:19 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	display_table(char **table)
{
	int i;

	i = 0;
	while (table[i])
		ft_putendl(table[i++]);
}

int		table_len(char **table_tetri)
{
	int	i;

	i = 0;
	while (table_tetri[i])
		i++;
	return (i);
}

char	***list_tetriminos(char **table_tetri)
{
	char	***list_tetri;
	int		i;

	if ((list_tetri = (char ***)malloc(sizeof(char **) * 
					table_len(table_tetri) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (table_tetri[i])
	{
		list_tetri[i] = ft_strsplit(table_tetri[i], '\n');
		free(table_tetri[i]);
		i++;
	}
	free(table_tetri);
	list_tetri[i] = NULL;
	return (list_tetri);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:13:42 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/10 12:10:17 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


// THIS FILE NEEDS TO BE SPLIT IN DIFFERENT FILES FOR CLARITY

char	*copy_trim(char **indiv_tetri)
{
	char	*trim_cpy;
	int i;
	int j;

	i = 0;
	j = 0;
	if ((trim_cpy = (char *)malloc(sizeof(char) * 9)) == NULL)
		return (NULL);
	while (indiv_tetri[i])
	{
		while (indiv_tetri[i][j])
		{
			if (indiv_tetri[i][j] != '-')
			{
				*trim_cpy = indiv_tetri[i][j];
				trim_cpy += 1;	
			}
			j++;
		}
		i++;
	}
	*trim_cpy = '\0';
	ft_putstr(trim_cpy);
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
	int 	i;

	i = 0;
	while (i < 5)
		if (tetri_row[i++] == '#')
			return ;
	while (i < 10)
		tetri_row[i++ % 5] = '-';
}

char	*remove_edges(char **indiv_tetri)
{
	int		i;
	char	*trim_cpy;

	i = 0;
	trim_cpy = NULL;
	while (i < 4)
		trim_row(indiv_tetri[i++]);
	while (i < 8)
		trim_col(indiv_tetri, (i++ % 4));
	while (i < 12)
		ft_putstr(indiv_tetri[i++ % 4]);
	trim_cpy = copy_trim(indiv_tetri);
	return (trim_cpy);
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

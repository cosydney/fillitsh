/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim-tetrimonos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:05:27 by sycohen           #+#    #+#             */
/*   Updated: 2016/11/10 08:17:55 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*trim_rows(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	i = 0;
	if (count == 4)
		while (i < 4)
		{
			str[i] = '-';
			i++;
		}
	return (str);
}

char	**trim_tetrimonos(char **tetri)
{
	int i;
	int j;
	int count;

	i = -1;
	j = -1;
	count = 0;
	while (i++ < 5)
		trim_rows(tetri[i]);
	i = 0;
	while (j++ < 4)
	{
		count = 0;
		i = -1;
		while (i++ < 4)
			if (tetri[i][j] == '.' || tetri[i][j] == '-')
				count++;
		i = -1;
		if (count == 4)
			while (i++ < 4)
				tetri[i][j] = '-';
	}
	return (tetri);
}

#include <stdio.h>

int		main(void)
{
	char	**tetrimonos;
	int		i;

	i = 0;
	tetrimonos = malloc(50);
	while (i < 5)
	{
		tetrimonos[i] = malloc(50);
		i++;
	}
	tetrimonos[0] = strdup("....\n");
	tetrimonos[1] = strdup("....\n");
	tetrimonos[2] = strdup("###.\n");
	tetrimonos[3] = strdup(".#..\n");
	tetrimonos = trim_tetrimonos(tetrimonos);
	printf("%s", tetrimonos[0]);
	printf("%s", tetrimonos[1]);
	printf("%s", tetrimonos[2]);
	printf("%s", tetrimonos[3]);
}

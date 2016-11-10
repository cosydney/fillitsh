/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:57:35 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/09 20:26:52 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		chars_check(char str)
{
	if (str != '.' && str != '#' && str != '\n')
		return (1);
	else
		return (0);
}

/*	check format verifie 1. nbre de lignes
**  2. la hauteur 3.Les caracteres . # et les '\n'
**  4. qu'il y a bien 4 #.
*/

int		check_format(char *str, int height, int line, int dash)
{
	while (*str)
	{
		ft_putchar(*str);
		if (chars_check(*str))
			return (1);
		if (*str == '#')
			dash++;
		if (*str == '\n')
		{
			if (line != 4)
				return (1);
			line = -1;
			height++;
		}
		if (*str == '\n' && *(str + 1) == '\n')
		{
			if (height % 4 != 0 || dash % 4 != 0 || *(str + 2) == '\0')
				return (1);
			str++;
		}
		line++;
		str++;
	}
	return ((height % 4 == 0) ? 0 : 1);
}

char	*check_input(char *str_data)
{
	if (check_format(str_data, 0, 0, 0))
		return (NULL);
	return (str_data);
}

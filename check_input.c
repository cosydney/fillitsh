/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:57:35 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/12 08:50:40 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
**	Simple function to check whether a character is a valid one
**	Returns 0 if the char is correct, 1 otherwise
*/

int		chars_check(char str)
{
	if (str != '.' && str != '#' && str != '\n')
		return (1);
	else
		return (0);
}

/*
**	Verifies the overall format of the file data. That includes height, nb
**	of char per line, number of # and presence of only '.' '.\n' and '#'
**  Returns 0 if the file is correct, 1 otherwise.
*/

int		check_format(char *str, int height, int line, int dash)
{
	while (*str)
	{
		if (chars_check(*str))
			return (1);
		if (*str == '\n')
		{
			if (line != 4)
				return (1);
			line = -1;
			height++;
		}
		if (*str == '#')
			dash++;
		if (*str == '\n' && ((*(str + 1) == '\n') || (*(str + 1) == '\0')))
		{
			if (height % 4 != 0 || dash != 4)
				return (1);
			dash = 0;
			str++;
		}
		line++;
		str++;
	}
	return ((*(str - 1) != '\n') && (height % 4 == 0) ? 0 : 1);
}

char	*check_input(char *str_data)
{
	if (check_format(str_data, 0, 0, 0))
		return (NULL);
	return (str_data);
}

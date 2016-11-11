/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:57:35 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 19:40:48 by sycohen          ###   ########.fr       */
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

int		check_linked(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#')
			count++;
		if (str[i] == '#' && str[i + 5] == '#')
			count++;
		if (str[i] == '\n' && ((str[i + 1] == '\n') || (str[i + 1] == '\0')))
		{
			if (count != 3 && count != 4)
				return (1);
			else
				count = 0;
		}
		i++;
	}
	return (0);
}

char	*check_input(char *str_data)
{
	if (check_format(str_data, 0, 0, 0))
		return (NULL);
//	if (check_linked(str_data))
//		return (NULL);
	return (str_data);
}

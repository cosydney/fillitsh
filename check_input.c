/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:57:35 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/09 16:54:20 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		chars_check(char str)
{
	if (str != '.' && str != '#' && str != '\n')
		return (1);
	else
		return (0);
}

int		check(char *str)
{
	int line;
	int height;

	height = 0;
	line = 0;
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
		if (*str == '\n' && *(str + 1) == '\n')
		{
			if (height % 4 != 0)
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
	if (check(str_data))
		return (NULL);
	return (str_data);
}

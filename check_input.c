/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:57:35 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/09 12:54:41 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		syntax_check(char *str_data)
{
	int		char_lines;
	int		nb_rows;

	char_lines = 0;
	nb_rows = 0;
	while (*str_data)
	{
		ft_putchar(*str_data);
		if ((*str_data != '.' && *str_data != '#' && *str_data != '\n') || char_lines > 4)
			return (1);
		if (*str_data == '\n')
		{
			if (char_lines != 4)
				return (1);
			char_lines = -1;
			nb_rows++;
		}
		char_lines++;
		str_data++;
	}
	return (0);
}

char	*check_input(char *str_data)
{
	if (syntax_check(str_data))
		return (NULL);
	return (str_data);
}

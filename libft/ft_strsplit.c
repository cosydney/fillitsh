/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:35:01 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/07 10:39:17 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_strlenc1(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strndup1(const char *s1, size_t n)
{
	char			*dup;
	unsigned int	i;

	dup = (char *)malloc(sizeof(*dup) * (n + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	nb_words(char *str, char c)
{
	int i;
	int compteur;
	int flag;

	i = 0;
	compteur = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			compteur++;
			if (flag == 1)
				compteur--;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	if (flag == 1)
		compteur--;
	return (compteur + 1);
}

char		**ft_strsplit(char *str, char c)
{
	char			**b;
	unsigned int	j;

	j = 0;
	if (!str)
		return (NULL);
	if ((b = (char **)(malloc(sizeof(*b) * (nb_words(str, c) + 1)))) == NULL)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			b[j] = ft_strndup1(str, ft_strlenc(str, c));
			str += (ft_strlenc1(str, c) - 1);
			j++;
		}
		str++;
	}
	b[j] = 0;
	return (b);
}

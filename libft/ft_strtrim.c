/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:29:30 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/06 14:38:35 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	if (!(*s))
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
	{
		start++;
		if (start == ft_strlen(s) - 1)
			return (ft_strdup(""));
	}
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	if (end == 0)
		return ((char *)s);
	return (ft_strsub(s, start, (size_t)end - start + 1));
}

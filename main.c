/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:49:00 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/10 10:22:16 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("usage: fillit tetriminos_file", 2);
		return (1);
	}
	if (launch_fillit(av))
	{
		ft_putendl("Error.");
		return (2);
	}
	return (0);
}

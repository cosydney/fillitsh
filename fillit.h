/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:24:48 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 16:38:40 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

int				launch_fillit(char **av);

char			*open_close_file(char *path);

char			*check_input(char *str_data);

char			**check_tetriminos(char *str_data);

char			*remove_edges(char **indiv_tetri);

int				compare_tetris(char **tetris);

char			***list_tetriminos(char	**table_tetri);
void			display_table(char **table);
int				list_len(char ***list_tetri);

int				solve(char ***list_tetri);

#endif

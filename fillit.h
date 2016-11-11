/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:24:48 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/11 09:09:43 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int		launch_fillit(char **av);

char	*open_close_file(char *path);

char	*check_input(char *str_data);

char	**check_tetriminos(char *str_data);

char	*remove_edges(char **indiv_tetri);

int		compare_tetris(char **tetris);

char	***list_tetriminos(char	**table_tetri);

#endif

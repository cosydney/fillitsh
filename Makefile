# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 10:05:07 by hdelaby           #+#    #+#              #
#    Updated: 2016/11/14 10:40:02 by hdelaby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBNAME = lib;
LIBPATH = -C ./libft/

OBJS = main.o init.o get_input.o check_input.o check_tetriminos.o \
	   trim_tetriminos.o compare_tetri.o list_tetriminos.o solve.o

all: $(NAME)

$(NAME): $(OBJS)
	make $(LIBPATH)
	$(CC) $(CFLAGS) -L./libft -lft -o $@ $^

%.o: %.c
	$(CC) -c -o  $@ $< -I./libft $(CFLAGS)

clean:
	rm -f $(OBJS)
	make clean $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

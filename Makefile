# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 12:30:05 by hdelaby           #+#    #+#              #
#    Updated: 2016/11/10 16:57:09 by sycohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBNAME = lib;
LIBPATH = -C ./libft/

SRCS = main.c init.c get_input.c check_input.c check_tetriminos.c \
	   trim_tetriminos.c compare_tetri.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -L./libft -lft -o $(NAME) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -I./libft -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	make $(LIBPATH)


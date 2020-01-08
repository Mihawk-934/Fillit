# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miclaude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 10:34:55 by miclaude          #+#    #+#              #
#    Updated: 2017/12/18 22:52:34 by miclaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDES = .

LIBFT = libft/libft.a

CC = gcc

SRC = ft_open.c ft_check.c ft_map1.c ft_map2.c main.c

CFLAGS = -c -Wall -Wextra -Werror -I$(INCLUDES) -Ilibft

LFLAGS  = -L libft/ -lft

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(INCLUDES)
	$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

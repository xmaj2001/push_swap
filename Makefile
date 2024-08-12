# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 11:36:52 by xjose             #+#    #+#              #
#    Updated: 2024/08/12 11:36:52 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap

LIBFT = ./libft
CFLAGS = -Wall -Wextra -Werror
CFILS = srcs/*.c srcs/rules/*.c srcs/utils/*.c 
CC = cc


all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT)
	$(CC) main.c $(CFILS) -o $(NAME) -L$(LIBFT) -lft

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f *.o

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
	
rec: fclean all
	$(MAKE) -C $(LIBFT) rec
	rm -f *.o

recc: fclean all
	$(MAKE) -C $(LIBFT) rec
	rm -f *.o
	clear
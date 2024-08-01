# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 17:11:20 by hk                #+#    #+#              #
#    Updated: 2024/07/31 21:23:25 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = app

LIBFT = ./libft
CFLAGS = -Wall -Wextra -Werror
CFILS = srcs/app/*.c srcs/rules/*.c srcs/utils/*.c 
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

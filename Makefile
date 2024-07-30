# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 17:11:20 by hk                #+#    #+#              #
#    Updated: 2024/07/30 02:32:35 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = app

LIBFT = ./libft
CFLAGS = -Wall -Wextra -Werror

CC = cc


all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT)
	$(CC) main.c srcs/*.c srcs/rules/*.c -o $(NAME) -L$(LIBFT) -lft

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

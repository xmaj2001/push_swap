# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 11:36:52 by xjose             #+#    #+#              #
#    Updated: 2024/08/13 15:15:56 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/args.c\
		./srcs/check.c\
		./srcs/ft_calculates.c\

RULES = ./srcs/rules/rules_push.c\
		./srcs/rules/rules_rotate.c\
		./srcs/rules/rules_swap.c\

UTILS = ./srcs/utils/get_ultils2.c\
		./srcs/utils/get_ultils.c\
		./srcs/utils/set_ultils.c\
		./srcs/utils/stack_ultils.c\
		./srcs/utils/utlis_item.c\
		./srcs/utils/validates_ultils.c

CFILS = $(SRCS) $(RULES) $(UTILS)

CC = cc


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c $(CFILS) -L$(LIBFT) -lft -o $(NAME) 
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
	
rec: fclean all
	rm -f *.o

recc: fclean all
	rm -f *.o
	clear
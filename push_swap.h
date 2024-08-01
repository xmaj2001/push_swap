/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:16:09 by xjose             #+#    #+#             */
/*   Updated: 2024/07/31 21:21:48 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_item
{
	int				value;
	struct s_item	*next;
}					t_item;

enum				e_rules
{
	SA = 0,
	SB = 1,
	RA = 2,
	RB = 3,
	RRA = 4,
	RRB = 5,
	END = -1
};

enum				e_rules_two
{
	SS = 1,
	RR = 2,
	RRR = 3,
	PA = 4,
	PB = 5,
	ENDTWO = -1
};

int					ft_is_ordered(t_item *pilha);
int					ft_max_value(t_item **pilha);
int					ft_count_items(t_item **pilha);

void				ft_additem(t_item **pilha, int value);
void				ft_remove_all(t_item **pilha);
void				ft_rules(t_item **pilha, ...);
void				ft_rules_two(t_item **pilha1, t_item **pilha2, ...);
void				ft_push(t_item **pilha1, t_item **pilha2, char *ms);
void				ft_rotate(t_item **pilha, char *ms);
void				ft_rrotate(t_item **pilha, char *ms);
void				ft_swap(t_item **pilha, char *ms);

void				ft_calculate_three(t_item **pilha);

t_item				*ft_getlast_item(t_item *pilha);
t_item				*ft_get_penultemate_item(t_item *pilha);
#endif

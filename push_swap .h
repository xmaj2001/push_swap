/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap .h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:16:09 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 15:00:09 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include "./libft/libft.h"
#include <stdlib.h>

typedef struct s_item
{
    int value;
    struct s_item *next;
} t_item;

enum e_rules
{
    SA = 0,
    SB = 1,
    SS = 2,
    RA = 3,
    RB = 4,
    RR = 5,
    RRA = 6,
    RRB = 7,
    RRR = 8,
    PA = 9,
    PB = 10,
    END = -1
};

int ft_count_items(t_item **head);

void ft_rules(t_item **head, ...);
void ft_additem(t_item **head, int value);
void ft_remove_all(t_item **head);
void ft_sa(t_item **head);
void ft_sb(t_item **head);
void ft_ra(t_item **head);
void ft_rra(t_item **head);
void teste(t_item **head);
int	ft_isord(t_item *head);
t_item *ft_getlast_item(t_item *head);
t_item *ft_get_penultemate_item(t_item *head);
#endif

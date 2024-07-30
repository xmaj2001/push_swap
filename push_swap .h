/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap .h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:16:09 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 03:02:22 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>

typedef struct s_item
{
    int value;
    struct s_item *next;
} t_item;

void ft_addlast(t_item **head);
void ft_additem(t_item **head, int value);
void ft_remove_all(t_item **head);
void ft_sa(t_item **head);
void ft_sb(t_item **head);
void ft_ra(t_item **head);
void ft_rra(t_item **head);

t_item *ft_getlast_item(t_item *head);
t_item *ft_get_penultemate_item(t_item *head);
#endif

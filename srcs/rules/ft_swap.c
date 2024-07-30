/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:15:39 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 14:01:52 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap .h"

void ft_sa(t_item **head)
{
    t_item *frist;
    t_item *second;

    if (*head == NULL || (*head)->next == NULL)
        return;
    second = *head;
    frist = second->next;
    second->next = frist->next;
    frist->next = second;
    *head = frist;
    ft_printf("SA\n");
}

void ft_sb(t_item **head)
{
    t_item *frist;
    t_item *second;

    if (*head == NULL || (*head)->next == NULL)
        return;
    second = *head;
    frist = second->next;
    second->next = frist->next;
    frist->next = second;
    *head = frist;
    ft_printf("SB\n");
}
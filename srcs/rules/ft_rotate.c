/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:43:41 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 14:02:41 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap .h"

void ft_ra(t_item **head)
{
	t_item *frist;
	t_item *last;

	if (*head == NULL || (*head)->next == NULL)
		return;
	frist = *head;
	*head = frist->next;
	frist->next = NULL;
	last = ft_getlast_item(*head);
	last->next = frist;
	ft_printf("RA\n");
}

void ft_rra(t_item **head)
{
	t_item *penultema;
	t_item *last;

	if (*head == NULL || (*head)->next == NULL)
		return;
	
	penultema = ft_get_penultemate_item(*head);
	last = penultema->next;
	penultema->next = NULL;
	last->next = *head;
	*head = last;
	ft_printf("RRA\n");
}

void ft_rb(t_item **head)
{
	t_item *frist;
	t_item *last;

	if (*head == NULL || (*head)->next == NULL)
		return;
	frist = *head;
	*head = frist->next;
	frist->next = NULL;
	last = ft_getlast_item(*head);
	last->next = frist;
	ft_printf("RB\n");
}

void ft_rrb(t_item **head)
{
	t_item *penultema;
	t_item *last;

	if (*head == NULL || (*head)->next == NULL)
		return;
	
	penultema = ft_get_penultemate_item(*head);
	last = penultema->next;
	penultema->next = NULL;
	last->next = *head;
	*head = last;
	ft_printf("RRB\n");
}

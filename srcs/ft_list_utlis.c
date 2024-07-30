/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utlis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:16:01 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 03:06:25 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap .h"

void ft_additem(t_item **head, int value)
{
	t_item *new_item;
	t_item *last;

	new_item = (t_item *)malloc(sizeof(t_item));
	if (new_item == NULL)
		return;
	if (*head == NULL)
	{
		new_item->value = value;
		new_item->next = NULL;
		*head = new_item;
	}
	else
	{
		last = ft_getlast_item(*head);
		last->next = new_item;
		new_item->value = value;
		new_item->next = NULL;
	}
}

void ft_remove_all(t_item **head)
{
	t_item *tmp;

	tmp = *head;
	if (tmp == NULL)
		return;
	while (tmp != NULL)
	{
		*head = tmp->next;
		free(tmp);
		tmp = *head;
	}
}

t_item *ft_getlast_item(t_item *head)
{
	t_item *last;

	last = head;
	if (last == NULL)
		return NULL;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_item *ft_get_penultemate_item(t_item *head)
{
	t_item *penultemate;

	penultemate = head;
	if (penultemate == NULL)
		return NULL;
	while (penultemate->next != NULL && penultemate->next->next != NULL)
		penultemate = penultemate->next;
	return (penultemate);
}

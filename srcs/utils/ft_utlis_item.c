/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:48:46 by xjose             #+#    #+#             */
/*   Updated: 2024/08/02 15:52:09 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

int ft_count_items(t_item *head)
{
	t_item *tmp;
	int len;

	if (head == NULL)
		return (0);
	tmp = head;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int ft_max_value(t_item *head)
{
	t_item *tmp;
	int max;

	if (head == NULL)
		return (0);
	tmp = head;
	max = 0;
	while (tmp != NULL)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int ft_min_value(t_item *head)
{
	t_item *tmp;
	int min;

	if (head == NULL)
		return (0);
	tmp = head;
	min = 0;
	while (tmp != NULL)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

t_item *ft_min_item(t_item *head)
{
	t_item *tmp;
	t_item *min;

	if (head == NULL)
		return (0);
	tmp = head;
	min = head;
	while (tmp != NULL)
	{
		if (min->value > tmp->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int ft_is_ordered(t_item *head)
{
	t_item *tmp;
	int result;

	if (head == NULL)
		return (0);
	tmp = head;
	result = 0;
	while (tmp != NULL)
	{
		if (result < tmp->value)
			result = tmp->value;
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

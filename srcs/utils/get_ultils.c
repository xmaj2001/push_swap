/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ultils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:48:46 by xjose             #+#    #+#             */
/*   Updated: 2024/08/16 16:58:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <limits.h>

int	get_max_value(t_stack *stack)
{
	t_stack	*item;
	int		max;

	if (stack == NULL)
		return (0);
	item = stack;
	max = INT_MIN;
	while (item != NULL)
	{
		if (max < item->value)
			max = item->value;
		item = item->next;
	}
	return (max);
}

int	get_min_value(t_stack *stack)
{
	t_stack	*item;
	int		min;

	if (stack == NULL)
		return (0);
	item = stack;
	min = 0;
	while (item != NULL)
	{
		if (min > item->value)
			min = item->value;
		item = item->next;
	}
	return (min);
}

t_stack	*get_min_item(t_stack *stack)
{
	t_stack	*item;
	t_stack	*min;

	if (stack == NULL)
		return (0);
	item = stack;
	min = stack;
	while (item != NULL)
	{
		if (min->value > item->value)
			min = item;
		item = item->next;
	}
	return (min);
}

t_stack	*get_last_item(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_stack	*get_penultemate_item(t_stack *stack)
{
	t_stack	*penultemate;

	penultemate = stack;
	if (penultemate == NULL)
		return (NULL);
	while (penultemate->next != NULL && penultemate->next->next != NULL)
		penultemate = penultemate->next;
	return (penultemate);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ultils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:48:46 by xjose             #+#    #+#             */
/*   Updated: 2024/08/04 11:45:19 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <limits.h>

void	additem(t_stack **stack, int value)
{
	t_stack	*item;
	t_stack	*last;

	item = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (item == NULL)
		return ;
	item->value = value;
	if (*stack == NULL)
	{
		item->next = NULL;
		*stack = item;
	}
	else
	{
		last = get_last_item(*stack);
		item->next = NULL;
		last->next = item;
	}
}

void	set_index(t_stack *stack)
{
	int	medium;
	int	index;

	index = 0;
	medium = stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = index;
		if (stack->index <= medium)
			stack->medium = UP;
		else
			stack->medium = DOWN;
		stack = stack->next;
		index++;
	}
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*item;
	int		best_match;

	while (stack_b != NULL)
	{
		best_match = INT_MAX;
		item = stack_a;
		while (item != NULL)
		{
			if (stack_b->value < item->value && item->value < best_match)
			{
				best_match = item->value;
				stack_b->target = item;
			}
			item = item->next;
		}
		if (best_match == INT_MAX)
			stack_b->target = get_min_item(stack_a);
		stack_b = stack_b->next;
	}
}

void	set_numbers_operations(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*item;

	item = stack_b;
	while (stack_b)
	{
		stack_b->operation = stack_b->index;
		if (stack_b->medium == DOWN)
			stack_b->operation = stack_len(item) - stack_b->index;
		if (stack_b->target->medium == UP)
			stack_b->operation += stack_b->target->index;
		else
			stack_b->operation = stack_len(stack_a);
		-stack_b->target->index;
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack *stack_b)
{
	int		cheapest;
	t_stack	*item;

	cheapest = INT_MAX;
	while (stack_b)
	{
		if (stack_b->operation < cheapest)
		{
			cheapest = stack_b->operation;
			item = stack_b;
		}
		else
			stack_b->cheapest = 0;
		stack_b = stack_b->next;
	}
	item->cheapest = 1;
}

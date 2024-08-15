/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:03:00 by xjose             #+#    #+#             */
/*   Updated: 2024/08/15 15:30:26 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_top(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*item;

	item = get_cheapest_operation(*stack_b);
	while (*stack_a != item->target && *stack_b != item)
	{
		if (item->target->medium == UP && item->medium == UP)
			rules_rotates(stack_a, stack_b);
		else
			rules_rrotates(stack_a, stack_b);
	}
	while (*stack_a != item->target)
	{
		if (item->target->medium == UP)
			rules_rotate(stack_a, "ra\n");
		else
			rules_rrotate(stack_a, "rra\n");
	}
	while (*stack_b != item)
	{
		if (item->medium == UP)
			rules_rotate(stack_b, "rb\n");
		else
			rules_rrotate(stack_b, "rrb\n");
	}
	rules_push(stack_b, stack_a, "pa");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ultils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:48:46 by xjose             #+#    #+#             */
/*   Updated: 2024/08/15 15:57:57 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*get_cheapest_operation(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	gettarget_is_greater(t_stack *stack_a, t_stack *stack_b)
{
	return ((stack_len(stack_a) - stack_b->target->index) > stack_b->operation);
}

int	get_def(t_stack *stack_a, t_stack *stack_b)
{
	return ((stack_len(stack_a) - stack_b->target->index));
}

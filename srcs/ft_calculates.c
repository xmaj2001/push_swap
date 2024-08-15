/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:02:02 by xjose             #+#    #+#             */
/*   Updated: 2024/08/13 17:49:06 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void calculate_three(t_stack **pilha)
{
	int max;

	max = get_max_value(*pilha);
	while (ft_is_ordered(*pilha) != 1)
	{
		if (max == (*pilha)->value)
			rules_rotate(pilha, "ra\n");
		else if (max == (*pilha)->next->value)
			rules_rrotate(pilha, "rra\n");
		else if (max == (*pilha)->next->next->value)
			rules_swap(pilha, "sa");
	}
}

void calculate_plus(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_len(*stack_a) > 3)
		rules_push(stack_a, stack_b, "pb");
	calculate_three(stack_a);
	while (stack_len(*stack_b) > 0)
	{
		set_index(*stack_a);
		set_index(*stack_b);
		set_target(*stack_a, *stack_b);
		set_numbers_operations(*stack_a, *stack_b);
		set_cheapest(*stack_b);
		check_top(stack_a, stack_b);
	}
	set_index(*stack_a);
	while (ft_is_ordered(*stack_a) != 1)
	{
		if (get_min_item(*stack_a)->medium == DOWN)
			rules_rrotate(stack_a, "rra\n");
		else
			rules_rotate(stack_a, "ra\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:43:41 by xjose             #+#    #+#             */
/*   Updated: 2024/08/07 14:12:10 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rules_rotate(t_stack **stack, char *ms)
{
	t_stack	*frist;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = get_last_item(*stack);
	frist = *stack;
	*stack = frist->next;
	frist->next = NULL;
	last->next = frist;
	ft_printf("%s", ms);
}

void	rules_rrotate(t_stack **stack, char *ms)
{
	t_stack	*penultema;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	penultema = get_penultemate_item(*stack);
	last = penultema->next;
	penultema->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("%s", ms);
}

void	rules_rotates(t_stack **stack_a, t_stack **stack_b)
{
	rules_rotate(stack_a, "");
	rules_rotate(stack_b, "");
	ft_printf("rr\n");
}

void	rules_rrotates(t_stack **stack_a, t_stack **stack_b)
{
	rules_rrotate(stack_a, "");
	rules_rrotate(stack_b, "");
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:15:39 by xjose             #+#    #+#             */
/*   Updated: 2024/08/03 19:34:41 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rules_swap(t_stack **stack, char *ms)
{
	t_stack	*frist;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	frist = *stack;
	second = frist->next;
	frist->next = second->next;
	second->next = frist;
	*stack = second;
	ft_printf("%s\n", ms);
}

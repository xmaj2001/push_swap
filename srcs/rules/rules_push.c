/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:55:28 by xjose             #+#    #+#             */
/*   Updated: 2024/08/13 15:10:28 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rules_push(t_stack **stack1, t_stack **stack2, char *ms)
{
	t_stack	*item;

	if (*stack1 == NULL)
		return ;
	item = *stack1;
	*stack1 = item->next;
	item->next = *stack2;
	*stack2 = item;
	ft_putstr(ms);
	ft_putstr("\n");
}

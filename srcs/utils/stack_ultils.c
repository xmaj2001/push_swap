/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ultils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:48:46 by xjose             #+#    #+#             */
/*   Updated: 2024/08/04 11:19:31 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*item;
	int		len;

	if (stack == NULL)
		return (0);
	item = stack;
	len = 0;
	while (item != NULL)
	{
		item = item->next;
		len++;
	}
	return (len);
}

void	clean_stack(t_stack **stack)
{
	t_stack	*item;

	item = *stack;
	if (item == NULL)
		return ;
	while (item != NULL)
	{
		*stack = item->next;
		free(item);
		item = *stack;
	}
}



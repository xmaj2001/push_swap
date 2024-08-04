/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:48:46 by xjose             #+#    #+#             */
/*   Updated: 2024/08/04 14:53:50 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_is_ordered(t_stack *stack)
{
	t_stack	*item;
	int		result;

	if (stack == NULL)
		return (0);
	item = stack;
	result = item->value;
	while (item != NULL)
	{
		if (result <= item->value)
			result = item->value;
		else
			return (0);
		item = item->next;
	}
	return (1);
}

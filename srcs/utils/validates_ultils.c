/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates_ultils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:39:29 by xjose             #+#    #+#             */
/*   Updated: 2024/08/18 12:49:46 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	validate_number(char *str_nbr)
{
	int	i;

	i = 0;
	while (str_nbr[i])
	{
		if (!ft_isdigit(str_nbr[i]))
		{
			if ((str_nbr[i] != '-' && str_nbr[i] != '+'))
				return (0);
			if (!ft_isdigit(str_nbr[i + 1]))
				return (0);
			if (i != 0 && ft_isdigit(str_nbr[i - 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	exist_number(t_stack *stack, int value)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

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

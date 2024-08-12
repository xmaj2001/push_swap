/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates_ultils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:39:29 by xjose             #+#    #+#             */
/*   Updated: 2024/08/12 09:34:29 by xjose            ###   ########.fr       */
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
			if ((str_nbr[i] == '-' && !ft_isdigit(str_nbr[i + 1])) || (str_nbr[i] == '-' && ft_isdigit(str_nbr[i - 1])))
				return (0);
			else if ((str_nbr[i] == '+' && !ft_isdigit(str_nbr[i + 1])) || (str_nbr[i] == '+' && ft_isdigit(str_nbr[i - 1])))
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



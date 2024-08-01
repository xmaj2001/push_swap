/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:02:02 by xjose             #+#    #+#             */
/*   Updated: 2024/07/31 21:18:49 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_calculate_three(t_item **pilha)
{
	int	max;

	max = ft_max_value(pilha);
	while (ft_is_ordered(*pilha) != 1)
	{
		if (max == (*pilha)->value)
			ft_rules(pilha, RA, END);
		else if (max == (*pilha)->next->value)
			ft_rules(pilha, RRA, END);
		else if (max == (*pilha)->next->next->value)
			ft_rules(pilha, SA, END);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:30:54 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 13:54:40 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap .h"
#include <stdarg.h>

void ft_rules(t_item **head, ...)
{
	enum e_rules rules;
	va_list list;

	va_start(list, head);
	rules = 0;
	while (rules != -1)
	{
		rules = va_arg(list, int);
		if (rules == SA)
			ft_sa(head);
		if (rules == SB)
			ft_sb(head);
		if (rules == RA)
			ft_ra(head);
		if (rules == RRA)
			ft_rra(head);
	}
	va_end(list);
}

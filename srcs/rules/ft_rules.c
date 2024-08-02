/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:30:54 by xjose             #+#    #+#             */
/*   Updated: 2024/08/02 15:54:34 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdarg.h>

static void	ft_rules_swap(t_item **pilha, enum e_rules rules)
{
	if (rules == SA)
		ft_swap(pilha, "sa");
	if (rules == SB)
		ft_swap(pilha, "sb");
}

static void	ft_rules_rotate(t_item **pilha, enum e_rules rules)
{
	if (rules == RA)
		ft_rotate(pilha, "ra\n");
	if (rules == RB)
		ft_rrotate(pilha, "rb\n");
	if (rules == RRA)
		ft_rrotate(pilha, "rra\n");
	if (rules == RRB)
		ft_rrotate(pilha, "rrb\n");
}

static void	ft_rules_two_pilha(t_item **pilha1, t_item **pilha2,
		enum e_rules_two rules)
{
	if (rules == PA)
		ft_push(pilha2, pilha1, "pa");
	if (rules == PB)
		ft_push(pilha1, pilha2, "pb");
}

void	ft_rules(t_item **head, ...)
{
	enum e_rules	rules;
	va_list			list;

	va_start(list, head);
	rules = 0;
	while (rules != -1)
	{
		rules = va_arg(list, int);
		ft_rules_swap(head, rules);
		ft_rules_rotate(head, rules);
	}
	va_end(list);
}

void	ft_rules_two(t_item **pilha1, t_item **pilha2, ...)
{
	enum e_rules_two	rules;
	va_list				list;

	va_start(list, pilha2);
	rules = 0;
	while (rules != -1)
	{
		ft_rules_two_pilha(pilha1, pilha2, rules);
		rules = va_arg(list, int);
	}
	va_end(list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:55:28 by xjose             #+#    #+#             */
/*   Updated: 2024/07/31 21:18:33 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_push(t_item **pilha1, t_item **pilha2, char *ms)
{
	t_item	*item;

	if (*pilha1 == NULL || *pilha2 == NULL)
		return ;
	item = *pilha1;
	*pilha1 = item->next;
	item->next = *pilha2;
	*pilha2 = item;
	ft_printf("%s\n", ms);
}

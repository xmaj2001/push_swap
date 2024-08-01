/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:15:39 by xjose             #+#    #+#             */
/*   Updated: 2024/07/31 21:18:19 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_swap(t_item **pilha, char *ms)
{
	t_item	*frist;
	t_item	*second;

	if (*pilha == NULL || (*pilha)->next == NULL)
		return ;
	frist = *pilha;
	second = frist->next;
	frist->next = second->next;
	second->next = frist;
	*pilha = second;
	ft_printf("%s\n", ms);
}

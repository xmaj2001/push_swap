/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:43:41 by xjose             #+#    #+#             */
/*   Updated: 2024/07/31 21:18:26 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_rotate(t_item **pilha, char *ms)
{
	t_item	*frist;
	t_item	*last;

	if (*pilha == NULL || (*pilha)->next == NULL)
		return ;
	last = ft_getlast_item(*pilha);
	frist = *pilha;
	*pilha = frist->next;
	frist->next = NULL;
	last->next = frist;
	ft_printf("%s\n", ms);
}

void	ft_rrotate(t_item **pilha, char *ms)
{
	t_item	*penultema;
	t_item	*last;

	if (*pilha == NULL || (*pilha)->next == NULL)
		return ;
	penultema = ft_get_penultemate_item(*pilha);
	last = penultema->next;
	penultema->next = NULL;
	last->next = *pilha;
	*pilha = last;
	ft_printf("%s\n", ms);
}

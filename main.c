/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:29:30 by xjose             #+#    #+#             */
/*   Updated: 2024/08/01 07:56:26 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	imprimir(t_item *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

int	main(void)
{
	t_item	*pilha;

	pilha = NULL;
	ft_additem(&pilha, 30);
	ft_additem(&pilha, 20);
	ft_additem(&pilha, 50);
	imprimir(pilha);
	printf("\n");
	ft_calculate_three(&pilha);
	printf("\n");
	imprimir(pilha);
	return (0);
}

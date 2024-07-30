/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:29:30 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 15:07:01 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap .h"
#include "push_swap .h"

void imprimir(t_item *list)
{
    while (list != NULL)
    {
        printf("%d\n", list->value);
        list = list->next;
    }
}

int main(void)
{
    t_item *pilha;
    int h;

    h = 0;
    pilha = NULL;

    //  ft_addlast(&pilha);
    ft_additem(&pilha, 20);
    ft_additem(&pilha, 50);
    ft_additem(&pilha, 30);
    // ft_rra(&pilha);
    imprimir(pilha);
    while (h == 0)
    {
        teste(&pilha);
        h = ft_isord(pilha);
    }
    printf("\n");
    imprimir(pilha);
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:54:58 by hk                #+#    #+#             */
/*   Updated: 2024/07/30 03:13:42 by xjose            ###   ########.fr       */
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
    t_item *header;

    header = NULL;

    //  ft_addlast(&header);
    ft_additem(&header, 10);
    ft_additem(&header, 20);
    ft_additem(&header, 30);
    ft_rra(&header);
    imprimir(header);
   
    return 0;
}


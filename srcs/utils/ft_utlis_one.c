/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:48:46 by xjose             #+#    #+#             */
/*   Updated: 2024/07/31 21:20:13 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_remove_all(t_item **head)
{
	t_item	*tmp;

	tmp = *head;
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		*head = tmp->next;
		free(tmp);
		tmp = *head;
	}
}

t_item	*ft_getlast_item(t_item *head)
{
	t_item	*last;

	last = head;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_item	*ft_get_penultemate_item(t_item *head)
{
	t_item	*penultemate;

	penultemate = head;
	if (penultemate == NULL)
		return (NULL);
	while (penultemate->next != NULL && penultemate->next->next != NULL)
		penultemate = penultemate->next;
	return (penultemate);
}

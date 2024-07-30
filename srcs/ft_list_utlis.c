/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utlis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:16:01 by xjose             #+#    #+#             */
/*   Updated: 2024/07/30 15:03:16 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap .h"

void ft_additem(t_item **head, int value)
{
	t_item *new_item;
	t_item *last;

	new_item = (t_item *)malloc(sizeof(t_item));
	if (new_item == NULL)
		return;
	if (*head == NULL)
	{
		new_item->value = value;
		new_item->next = NULL;
		*head = new_item;
	}
	else
	{
		last = ft_getlast_item(*head);
		last->next = new_item;
		new_item->value = value;
		new_item->next = NULL;
	}
}

void ft_remove_all(t_item **head)
{
	t_item *tmp;

	tmp = *head;
	if (tmp == NULL)
		return;
	while (tmp != NULL)
	{
		*head = tmp->next;
		free(tmp);
		tmp = *head;
	}
}

int ft_count_items(t_item **head)
{
	t_item *tmp;
	int len;

	if (*head == NULL)
		return (0);
	tmp = *head;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int ft_max_value(t_item **head)
{
	t_item *tmp;
	int max;

	if (*head == NULL)
		return (0);
	tmp = *head;
	max = 0;
	while (tmp != NULL)
	{
		if(max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

t_item *ft_getlast_item(t_item *head)
{
	t_item *last;

	last = head;
	if (last == NULL)
		return NULL;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_item *ft_get_penultemate_item(t_item *head)
{
	t_item *penultemate;

	penultemate = head;
	if (penultemate == NULL)
		return NULL;
	while (penultemate->next != NULL && penultemate->next->next != NULL)
		penultemate = penultemate->next;
	return (penultemate);
}

int	ft_isord(t_item *head)
{
	t_item *tmp;
	int result;

	if (head == NULL)
		return (0);
	tmp = head;
	result = 0;
	while (tmp != NULL)
	{
		if(result < tmp->value)
			result = tmp->value;
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	teste(t_item **head)
{
	int max = ft_max_value(head);
	if(max == (*head)->value)
		ft_rules(head, RA, END);
	else if(max == (*head)->next->value)
		ft_rules(head, RRA, END);
	else if(max == (*head)->next->next->value)
		ft_rules(head, SA, END);
}
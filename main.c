/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:29:30 by xjose             #+#    #+#             */
/*   Updated: 2024/08/02 16:47:27 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void imprimir(t_item *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}
void set_index(t_item *stack)
{
	int medium;
	int index;

	index = 0;
	medium = ft_count_items(stack) / 2;
	while (stack != NULL)
	{
		stack->index = index;
		if (stack->index <= medium)
			stack->up_medium = 1;
		else
			stack->up_medium = 0;
		stack = stack->next;
		index++;
	}
}

void set_cost(t_item *stack_a, t_item *stack_b)
{
	while (stack_b)
	{
		stack_b->cost = stack_b->index;
		if (stack_b->up_medium == 0)
			stack_b->cost = ft_count_items(stack_b) - stack_b->index;
		if (stack_b->target->up_medium == 1)
			stack_b->cost += stack_b->target->index;
		else
			stack_b->cost = ft_count_items(stack_a) - stack_b->target->index;
		stack_b = stack_b->next;
	}
}

void set_cheapest(t_item *stack_b)
{
	long cheapest;
	t_item *item;

	cheapest = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->cost < cheapest)
		{
			cheapest = stack_b->cost;
			item = stack_b;
		}
		else
			stack_b->cheapest = 0;
		stack_b = stack_b->next;
	}
	item->cheapest = 1;
}

void set_target(t_item *stack_a, t_item *stack_b)
{
	long best_match;
	t_item *tmp;

	while (stack_b != NULL)
	{
		best_match = LONG_MAX;
		tmp = stack_a;
		while (tmp != NULL)
		{
			if (stack_b->value < tmp->value && tmp->value < best_match)
			{
				best_match = tmp->value;
				stack_b->target = tmp;
			}
			tmp = tmp->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target = ft_min_item(stack_a);
		stack_b = stack_b->next;
	}
}

t_item *get_cheapest(t_item *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void check_top(t_item **stack_a, t_item **stack_b)
{
	t_item *item;

	item = get_cheapest(*stack_b);
	while (*stack_a != item->target && *stack_b != item)
	{
		if (item->target->up_medium && item->up_medium)
			ft_rrotates(stack_a, stack_b);
		else
			ft_rrrotates(stack_a, stack_b);
	}
	while (*stack_a != item->target)
	{
		if (item->target->up_medium)
			ft_rotate(stack_a, "ra\n");
		else
			ft_rrotate(stack_a, "rra\n");
	}
	while (*stack_b != item)
	{
		if (item->up_medium)
			ft_rotate(stack_b, "ra\n");
		else
			ft_rrotate(stack_b, "rra\n");
	}
	ft_push(stack_b, stack_a, "pa");
}

void calculate_plus(t_item **stack_a, t_item **stack_b)
{
	t_item *item;
	int max_value;

	while (ft_count_items(*stack_a) > 3)
		ft_rules_two(stack_a, stack_b, PB, ENDTWO);
	ft_calculate_three(stack_a);
	while (ft_count_items(*stack_b) > 0)
	{
		set_index(*stack_a);
		set_index(*stack_b);
		set_target(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		set_cheapest(*stack_b);
		check_top(stack_a, stack_b);
	}
}

int main(void)
{
	t_item *pilha_a = NULL;
	t_item *pilha_b = NULL;

	ft_additem(&pilha_a, 5);
	ft_additem(&pilha_a, 3);
	ft_additem(&pilha_a, 80);
	ft_additem(&pilha_a, 8);
	ft_additem(&pilha_a, 100);

	printf("Pilha A antes do push:\n");
	imprimir(pilha_a);

	// calculate_plus(&pilha_a, &pilha_b);
	calculate_plus(&pilha_a, &pilha_b);

	printf("\nPilha A depois do push:\n");
	imprimir(pilha_a);
	// printf("\nPilha B depois do push:\n");
	// imprimir(pilha_b);
	return (0);
}

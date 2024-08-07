/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:29:30 by xjose             #+#    #+#             */
/*   Updated: 2024/08/07 14:54:08 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <time.h>

void fill_stack_with_unique_numbers(t_stack **head, int count)
{
	int i;
	int is_unique;

	int used_numbers[100] = {0}; // Array para rastrear números já usados
	i = 0;
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	while (i < count)
	{
		int num = rand(); // Gera um número aleatório
		is_unique = 1;
		// Verifica se o número já foi usado
		for (int j = 0; j < i; j++)
		{
			if (used_numbers[j] == num)
			{
				is_unique = 0;
				break;
			}
		}
		// Se o número é único, adicione à pilha
		if (is_unique)
		{
			additem(head, num);
			used_numbers[i] = num;
			i++;
		}
	}
}

void imprimir(t_stack *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

static void init_stacks(t_datas **datas)
{
	(*datas)->stack_a = NULL;
	(*datas)->stack_b = NULL;
}

static void validate_number_main(t_stack **stack_a, char **numbers, int index)
{
	int value;

	value = ft_atoi(numbers[index]);
	additem(stack_a, value);
	// if (!exist_number(*stack_a, value))
	// 	additem(stack_a, value);
	// else
	// {
	// 	clean_stack(stack_a);
	// 	ft_printf("Error\n");
	// 	free(numbers);
	// 	exit(1);
	// }
}

static void add_numbers(t_stack **stack_a, char *argv[])
{
	int index;
	int index_arg;
	char **numbers;

	index_arg = 1;
	while (argv[index_arg])
	{
		numbers = ft_split(argv[index_arg], ' ');
		index = 0;
		while (numbers[index])
		{
			if (validate_number(numbers[index]))
				validate_number_main(stack_a, numbers, index);
			else
			{
				clean_stack(stack_a);
				ft_printf("Error\n");
				free(numbers);
				exit(1);
			}
			index++;
			free(numbers[index]);
		}
		free(numbers);
		index_arg++;
	}
}

int main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	add_numbers(&stack_a, argv);
	//calculate_plus(&stack_a, &stack_b);
	clean_stack(&stack_a);
	return (0);
}

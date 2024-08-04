/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:29:30 by xjose             #+#    #+#             */
/*   Updated: 2024/08/04 17:54:31 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <time.h>

void	fill_stack_with_unique_numbers(t_stack **head, int count)
{
	int	i;
	int	is_unique;

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
				break ;
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

void	imprimir(t_stack *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

static void	init_stacks(t_datas **datas)
{
	(*datas)->stack_a = NULL;
	(*datas)->stack_b = NULL;
}

static void	validate_number_main(t_datas **datas, int index)
{
	int	value;

	value = ft_atoi((*datas)->numbers[index]);
	if (!exist_number((*datas)->stack_a, value))
		additem(&(*datas)->stack_a, value);
	else
	{
		clean_stack(&(*datas)->stack_a);
		ft_printf("Error\n");
		free((*datas)->numbers);
		exit(1);
	}
}

static void	add_numbers(t_datas **datas, char *argv[])
{
	int	index;
	int	index_arg;

	index_arg = 1;
	while (argv[index_arg])
	{
		(*datas)->numbers = ft_split(argv[index_arg], ' ');
		index = 0;
		while ((*datas)->numbers[index])
		{
			if (validate_number((*datas)->numbers[index]))
				validate_number_main(datas, index);
			else
			{
				clean_stack(&(*datas)->stack_a);
				ft_printf("Error\n");
				free((*datas)->numbers);
				exit(1);
			}
			index++;
		}
		// free((*datas)->numbers);
		index_arg++;
	}
}

int	main(int argc, char *argv[])
{
	t_datas	*datas;

	if (argc < 2)
		return (1);
	init_stacks(&datas);
	// add_numbers(&datas, argv);
	fill_stack_with_unique_numbers(&datas->stack_a,100);
	calculate_plus(&datas->stack_a, &datas->stack_b);
	clean_stack(&datas->stack_a);
	return (0);
}

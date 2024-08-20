/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:32:00 by xjose             #+#    #+#             */
/*   Updated: 2024/08/20 09:46:54 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static	void	exit_app(t_stack **stack_a)
{
	clean_stack(stack_a);
	ft_putstr("Error\n");
	exit(1);
}

static	int	validate_number_main(t_stack **stack_a, char **numbers, int index)
{
	long long	value;

	value = ft_atoi(numbers[index]);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (!exist_number(*stack_a, value))
		additem(stack_a, value);
	else
		return (0);
	return (1);
}

void	add_string_arg(char *arg, t_stack **stack_a)
{
	int		index;
	char	**numbers;

	numbers = ft_split(arg, ' ');
	if (*numbers == NULL)
		exit_app2(numbers);
	index = 0;
	while (numbers[index])
	{
		if (validate_number(numbers[index]))
		{
			if (validate_number_main(stack_a, numbers, index) == 0)
			{
				free_split(numbers);
				exit_app(stack_a);
			}
		}
		else
		{
			free_split(numbers);
			exit_app(stack_a);
		}
		index++;
	}
	free_split(numbers);
}

void	add_args(t_stack **stack_a, char *argv[])
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (validate_number(argv[index]))
		{
			if (validate_number_main(stack_a, argv, index) == 0)
				exit_app(stack_a);
		}
		else
			exit_app(stack_a);
		index++;
	}
}

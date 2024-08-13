/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:32:00 by xjose             #+#    #+#             */
/*   Updated: 2024/08/13 15:12:56 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void free_split(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static char		**ft_splitx(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 256)))
		return (NULL);
	while (str[i] == ' ')
		i += 1;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
			return (NULL);
		while (str[i] != ' ' && str[i])
			split[k][j++] = str[i++];
		while (str[i] == ' ')
			i += 1;
		split[k][j] = '\0';
		k += 1;
	}
	split[k] = NULL;
	return (split);
}

static void exit_app(t_stack **stack_a)
{
	clean_stack(stack_a);
	ft_putstr("Error\n");
	exit(1);
}

static int validate_number_main(t_stack **stack_a, char **numbers, int index)
{
	int value;

	value = ft_atoi(numbers[index]);
	if (!exist_number(*stack_a, value))
		additem(stack_a, value);
	else
		return (0);
	return (1);
}

void add_string_arg(char *arg, t_stack **stack_a)
{
	int index;
	char **numbers;

	numbers = ft_splitx(arg);
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

void add_args(t_stack **stack_a, char *argv[])
{
	int index;

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

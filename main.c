/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:29:30 by xjose             #+#    #+#             */
/*   Updated: 2024/08/15 19:28:03 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			exit(1);
		add_string_arg(argv[1], &stack_a);
	}
	else
		add_args(&stack_a, argv);
	calculate_plus(&stack_a, &stack_b);
	clean_stack(&stack_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:16:09 by xjose             #+#    #+#             */
/*   Updated: 2024/08/13 15:14:57 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

enum				e_medium
{
	UP = 1,
	DOWN = 0
};

typedef struct s_stack
{
	int				value;
	int				index;
	int				cheapest;
	int				operation;
	enum e_medium	medium;
	struct s_stack	*next;
	struct s_stack	*target;
}					t_stack;

typedef struct s_datas
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			**numbers;
}					t_datas;

int					ft_is_ordered(t_stack *stack);
int					stack_len(t_stack *stack);

void				check_top(t_stack **stack_a, t_stack **stack_b);
void				clean_stack(t_stack **stack);

void				additem(t_stack **stack, int value);
void				set_index(t_stack *stack);
void				set_target(t_stack *stack_a, t_stack *stack_b);
void				set_numbers_operations(t_stack *stack_a, t_stack *stack_b);
void				set_cheapest(t_stack *stack_b);

void				rules_push(t_stack **stack1, t_stack **stack2, char *ms);
void				rules_rotate(t_stack **stack, char *ms);
void				rules_rrotate(t_stack **stack, char *ms);
void				rules_rotates(t_stack **stack_a, t_stack **stack_b);
void				rules_rrotates(t_stack **stack_a, t_stack **stack_b);
void				rules_swap(t_stack **stack, char *ms);

void				calculate_three(t_stack **stack);
void				calculate_plus(t_stack **stack_a, t_stack **stack_b);

int					validate_number(char *str_nbr);
void				add_string_arg(char	*arg, t_stack **stack_a);
void				add_args(t_stack **stack_a, char *argv[]);
int					exist_number(t_stack *stack, int value);

int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
void				ft_putstr(char *s);

int					get_max_value(t_stack *stack);
int					get_min_value(t_stack *stack);
t_stack				*get_min_item(t_stack *stack);
t_stack				*get_last_item(t_stack *stack);
t_stack				*get_penultemate_item(t_stack *stack);
t_stack				*get_cheapest_operation(t_stack *stack);
#endif

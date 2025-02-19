/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:37 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/19 12:51:23 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;
	int		value;

	if (argc < 2)
		return (1);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a)
		return (1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	i = 0;
	while (args[i])
	{
		value = ft_atoi(args[i]);
		if (is_valid_number(args[i]) && !is_duplicate(stack_a, value))
			append_node(stack_a, value);
		else
		{
			free_array(args);
			cleanup(stack_a, stack_b, "Error\n");
		}
		i++;
	}
	if (argc == 2)
		free_array(args);
	if (is_sorted(stack_a))
		cleanup(stack_a, stack_b, "");
	handle_small_stacks(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	a_to_b(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
	if (!is_sorted(stack_a))
		final_sort(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// print_stack(stack_a, 'a');

// ARG=$(seq 100 | shuf | tr '\n' ' ' ); ./push_swap $ARG | wc -l

// ARG="69 31 46 79 5 6 1"; ./push_swap $ARG | ./checker_linux $ARG

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		i;
// 	int		value;

// 	if (argc < 2)
// 		return (1);
// 	stack_a = init_stack();
// 	stack_b = init_stack();
// 	if (!stack_a || !stack_b)
// 		return (1);
// 	i = 1;
// 	while (i < argc)
// 	{
// 		value = ft_atoi(argv[i]);
// 		if (is_valid_number(argv[i]) && !is_duplicate(stack_a, value))
// 			append_node(stack_a, value);
// 		else
// 			cleanup(stack_a, stack_b, "Error\n");
// 		i++;
// 	}
// 	if (is_sorted(stack_a))
// 		cleanup(stack_a, stack_b, "");
// 	handle_small_stacks(stack_a, stack_b);
// 	pb(stack_a, stack_b);
// 	pb(stack_a, stack_b);
// 	a_to_b(stack_a, stack_b);
// 	b_to_a(stack_a, stack_b);
// 	if (!is_sorted(stack_a))
// 		final_sort(stack_a);
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	return (0);
// }
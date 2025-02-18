/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:37 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/18 17:33:35 by sdavi-al         ###   ########.fr       */
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

void	cleanup(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Error\n");
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		value;

	if (argc < 2)
		return (1);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (1);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (is_valid_number(argv[i]) && !is_duplicate(stack_a, value))
			append_node(stack_a, value);
		else
			cleanup(stack_a, stack_b);
		i++;
	}
	if (is_sorted(stack_a))
		cleanup(stack_a, stack_b);
	handle_small_stacks(stack_a, stack_b);
	push_initial_nodes(stack_a, stack_b);
	a_to_b(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
	if (!is_sorted(stack_a))
		final_sort(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// #include <stdio.h>

// void print_stack_info(t_stack *stack_a, t_stack *stack_b)
// {
//     t_node *node_a = stack_a->top;
//     t_node *node_b = stack_b->top;
//     printf("Stack A:\n");
//     while (node_a)
//     {
//         printf("Value: %d, Index: %d, Target: %d, Cost: %d\n", node_a->value,
//         node_a->index, node_a->target ? node_a->target->value : -1, node_a->cost);
//         node_a = node_a->next;
//     }
//     printf("Stack A Size: %d\n\n", stack_a->size);

//     printf("Stack B:\n");
//     while (node_b)
//     {
//     printf("Value: %d, Index: %d, Target: %d\n", node_b->value, node_b->index,
//                node_b->target ? node_b->target->value : -1);
//         node_b = node_b->next;
//     }
//     printf("Stack B Size: %d\n\n", stack_b->size);
// }
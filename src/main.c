/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:32:07 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/11 14:07:23 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	(*stack)->prev->next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	freexit(t_node **stack_a, t_node **stack_b, int exit_code)
{
	free_stack(stack_a);
	free_stack(stack_b);
	exit(exit_code);
}


int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!process_args(&stack_a, argv))
		cleanup(stack_a, stack_b, 1);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// pb(&stack_b, &stack_a);
	// pb(&stack_b, &stack_a);
	// pb(&stack_b, &stack_a);
	// pb(&stack_b, &stack_a);
	// pa(&stack_a, &stack_b);
	// print_stack(stack_a);
	// ft_printf("a\n\n");
	// print_stack(stack_b);
	cleanup(stack_a, stack_b, 0);
	return (0);
}

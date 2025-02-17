/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:37 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/17 16:11:04 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_node	*current;
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
		{
			cleanup(stack_a, stack_b);
			return (1);
		}
		i++;
	}

	// Initial stack state
	ft_printf("Initial Stack A:\n");
	print_stack(stack_a, 'A');

	// Push some elements to stack B for testing
	ft_printf("\nPushing elements to Stack B:\n");
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	// Update indices
	ft_printf("\nUpdating indices:\n");
	update_indices(stack_a);
	update_indices(stack_b);
	
	// Print updated indices
	ft_printf("\nStack A after updating indices:\n");
	current = stack_a->top;
	while (current)
	{
		ft_printf("Value: %d, Index: %d\n", current->value, current->index);
		current = current->next;
	}
	ft_printf("\nStack B after updating indices:\n");
	current = stack_b->top;
	while (current)
	{
		ft_printf("Value: %d, Index: %d\n", current->value, current->index);
		current = current->next;
	}

	// Find targets
	ft_printf("\nFinding targets:\n");
	find_targets(stack_a, stack_b);
	current = stack_a->top;
	while (current)
	{
		ft_printf("Node %d -> Target Index: %d\n", current->value, 
			current->target ? current->target->index : -1);
		current = current->next;
	}

	// Calculate costs
	ft_printf("\nCalculating costs:\n");
	calculate_costs(stack_a, stack_b);
	current = stack_a->top;
	while (current)
	{
		ft_printf("Node %d -> Cost: %d\n", current->value, current->cost);
		current = current->next;
	}

	// Free memory before exiting
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}





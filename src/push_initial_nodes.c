/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_initial_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:55:44 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/18 13:55:45 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	current = stack->top;
	min_node = current;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*find_max_node(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	current = stack->top;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

void	move_node_to_top(t_stack *stack, t_node *node)
{
	while (stack->top != node)
	{
		if (node->up_half)
			ra(stack);
		else
			rra(stack);
	}
}

void	push_initial_nodes(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;
	t_node	*largest;
	int		smallest_cost;
	int		largest_cost;

	smallest = find_min_node(stack_a);
	largest = find_max_node(stack_a);
	smallest_cost = m_cost(smallest->index, stack_a->size, smallest->up_half);
	largest_cost = m_cost(largest->index, stack_a->size, largest->up_half);
	if (smallest_cost <= largest_cost)
	{
		move_node_to_top(stack_a, smallest);
		pb(stack_a, stack_b);
		move_node_to_top(stack_a, largest);
		pb(stack_a, stack_b);
	}
	else
	{
		move_node_to_top(stack_a, largest);
		pb(stack_a, stack_b);
		move_node_to_top(stack_a, smallest);
		pb(stack_a, stack_b);
	}
}

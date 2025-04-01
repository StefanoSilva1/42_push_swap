/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:55:44 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/26 08:10:16 by sdavi-al         ###   ########.fr       */
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

void	move_node_to_top_b(t_stack *stack, t_node *node)
{
	while (stack->top != node)
	{
		if (node->up_half)
			rb(stack);
		else
			rrb(stack);
	}
}

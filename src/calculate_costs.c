/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:26:00 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/18 13:45:26 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	m_cost(int index, int size, int up_half)
{
	if (up_half)
		return (index - 1);
	return (size - index + 1);
}

int	compute_difference(int a, int b)
{
	if (a >= b)
		return (a - b);
	return (b - a);
}

int	close_limit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > stack_b->size)
		return (stack_a->size / 4);
	return (stack_b->size / 4);
}

void	node_cost(t_node *node, t_stack *stack_a, t_stack *stack_b, int close)
{
	int	cost_a;
	int	cost_b;
	int	difference;

	cost_a = m_cost(node->index, stack_a->size, node->up_half);
	cost_b = m_cost(node->target->index, stack_b->size, node->target->up_half);
	difference = compute_difference(node->index, node->target->index);
	if (node->up_half == node->target->up_half)
	{
		if (cost_a > cost_b)
			node->cost = cost_a;
		else
			node->cost = cost_b;
	}
	else if (difference <= close)
	{
		if (cost_a > cost_b)
			node->cost = cost_a;
		else
			node->cost = cost_b;
	}
	else
		node->cost = cost_a + cost_b;
}

void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	int		limit;
	t_node	*current;

	limit = close_limit(stack_a, stack_b);
	current = stack_a->top;
	while (current)
	{
		node_cost(current, stack_a, stack_b, limit);
		current = current->next;
	}
}

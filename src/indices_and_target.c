/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices_and_target.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:25:46 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/17 15:50:33 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_indices(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 1;
	current = stack->top;
	while (current)
	{
		current->index = i;
		current->in_first_half = (i <= stack->size / 2);
		current = current->next;
		i++;
	}
}


t_node	*find_target_for_node(t_stack *stack_b, int value)
{
	t_node	*current;
	t_node	*target_node;
	int		target_diff;
	int		diff;
	t_node	*max_node;

	target_node = NULL;
	target_diff = INT_MAX;
	current = stack_b->top;
	while (current)
	{
		if (current->value < value)
		{
			diff = value - current->value;
			if (diff < target_diff)
			{
				target_diff = diff;
				target_node = current;
			}
		}
		current = current->next;
	}
	if (!target_node && stack_b->top)
	{
		max_node = stack_b->top;
		current = stack_b->top;
		while (current)
		{
			if (current->value > max_node->value)
				max_node = current;
			current = current->next;
		}
		target_node = max_node;
	}
	return (target_node);
}

void	find_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_a->top;
	while (current)
	{
		if (stack_b->size > 0)
			current->target = find_target_for_node(stack_b, current->value);
		else
			current->target = NULL;
		current = current->next;
	}
}

void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*target;
	int		cost_a;
	int		cost_b;

	current = stack_a->top;
	while (current)
	{
		if (current->in_first_half)
			cost_a = current->index;
		else
			cost_a = stack_a->size - current->index;

		target = current->target;
		if (target)
		{
			if (target->in_first_half)
				cost_b = target->index;
			else
				cost_b = stack_b->size - target->index;
		}
		else
			cost_b = 0;

		if (current->in_first_half == target->in_first_half)
		{
			if (cost_a > cost_b)
				current->cost = cost_a;
			else
				current->cost = cost_b;
		}
		else
			current->cost = cost_a + cost_b;

		current = current->next;
	}
}



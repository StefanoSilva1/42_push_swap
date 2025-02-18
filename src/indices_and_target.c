/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices_and_target.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:25:46 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/18 13:13:40 by sdavi-al         ###   ########.fr       */
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
		current->up_half = (i <= stack->size / 2);
		current = current->next;
		i++;
	}
}

t_node	*find_target_candidate(t_stack *stack_b, int value)
{
	t_node	*current;
	t_node	*candidate;
	int		candidate_diff;
	int		diff;

	candidate = NULL;
	candidate_diff = INT_MAX;
	current = stack_b->top;
	while (current)
	{
		if (current->value < value)
		{
			diff = value - current->value;
			if (diff < candidate_diff)
			{
				candidate_diff = diff;
				candidate = current;
			}
		}
		current = current->next;
	}
	return (candidate);
}

t_node	*find_target_for_node(t_stack *stack_b, int value)
{
	t_node	*candidate;

	candidate = find_target_candidate(stack_b, value);
	if (!candidate && stack_b->top)
		candidate = find_max_node(stack_b);
	return (candidate);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:34:02 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/19 10:30:07 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_target_b(t_stack *stack_a, t_node *node_b)
{
	t_node	*current_a;
	t_node	*best_target;

	best_target = NULL;
	current_a = stack_a->top;
	while (current_a)
	{
		if (current_a->value > node_b->value && \
			(!best_target || current_a->value < best_target->value))
			best_target = current_a;
		current_a = current_a->next;
	}
	if (!best_target)
		best_target = find_min_node(stack_a);
	return (best_target);
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_b;
	t_node	*target_a;

	while (stack_b->top)
	{
		node_b = stack_b->top;
		target_a = find_target_b(stack_a, node_b);
		if (!target_a)
			return ;
		move_node_to_top(stack_a, target_a);
		pa(stack_a, stack_b);
	}
}

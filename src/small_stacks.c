/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:24:42 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/20 08:44:01 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack_a)
{
	if (stack_a->top->value > stack_a->top->next->value && \
		stack_a->top->value < stack_a->bottom->value)
		sa(stack_a);
	else if (stack_a->top->value > stack_a->top->next->value && \
			stack_a->top->next->value > stack_a->bottom->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (stack_a->top->value < stack_a->top->next->value && \
		stack_a->top->value > stack_a->bottom->value)
		rra(stack_a);
	else if (stack_a->top->value > stack_a->bottom->value)
		ra(stack_a);
	else if (stack_a->top->value < stack_a->top->next->value && \
			stack_a->top->next->value > stack_a->bottom->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;
	t_node	*current;

	min_node = stack_a->top;
	current = stack_a->top;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	while (stack_a->top != min_node)
	{
		if (min_node->up_half)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	handle_small_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		sa(stack_a);
		cleanup(stack_a, stack_b, "");
	}
	else if (stack_a->size == 3)
	{	
		sort_3(stack_a);
		cleanup(stack_a, stack_b, "");
	}
	else if (stack_a->size == 4)
	{
		sort_4(stack_a, stack_b);
		cleanup(stack_a, stack_b, "");
	}
}

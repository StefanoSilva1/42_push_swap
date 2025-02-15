/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:53:35 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/15 18:09:12 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*second_last;

	if (stack_a->size < 2)
		return ;
	last = stack_a->bottom;
	second_last = last->prev;
	stack_a->bottom = second_last;
	stack_a->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack_a->top;
	stack_a->top->prev = last;
	stack_a->top = last;
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*second_last;

	if (stack_b->size < 2)
		return ;
	last = stack_b->bottom;
	second_last = last->prev;
	stack_b->bottom = second_last;
	stack_b->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack_b->top;
	stack_b->top->prev = last;
	stack_b->top = last;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

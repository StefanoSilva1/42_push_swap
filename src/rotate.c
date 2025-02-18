/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:57:57 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/18 13:50:26 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;

	stack->top = first->next;
	stack->bottom = first;
	stack->top->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	update_indices(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	update_indices(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	update_indices(stack_a);
	update_indices(stack_b);
	write(1, "rr\n", 3);
}

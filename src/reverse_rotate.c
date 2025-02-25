/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:53:35 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/25 16:26:22 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (stack->size < 2)
		return ;
	last = stack->bottom;
	second_last = last->prev;
	stack->bottom = second_last;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	update_indices(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	update_indices(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	update_indices(stack_a);
	reverse_rotate(stack_b);
	update_indices(stack_b);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:53:36 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/10 19:10:06 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	last = (*stack)->prev;

	first->next = second->next;
	first->next->prev = first;
	second->prev = last;
	second->next = first;
	last->next = second;
	first->prev = second;
	*stack = second;
}

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:59:49 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/10 18:00:41 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	if (*stack == NULL)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*stack)->prev;
	new->next = *stack;
	new->prev = last;
	last->next = new;
	(*stack)->prev = new;
}

void	print_stack(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack;
	while (current->next != stack)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	ft_printf("%d\n", current->value);
}

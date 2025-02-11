/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:06:55 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/11 14:07:16 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	(*stack)->prev->next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	cleanup(t_node **stack_a, t_node **stack_b, int exit_code)
{
	free_stack(stack_a);
	free_stack(stack_b);
	exit(exit_code);
}

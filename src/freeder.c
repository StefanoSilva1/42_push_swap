/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:38:45 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/19 10:47:04 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_stack *stack_a, t_stack *stack_b, const char *msg)
{
	if (msg && msg[0] != '\0')
		ft_printf("%s", msg);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}

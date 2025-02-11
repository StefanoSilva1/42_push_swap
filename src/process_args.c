/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:48:39 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/10 18:01:20 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_node *stack, int value)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current->next != stack)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	if (current->value == value)
		return (1);
	return (0);
}

int	process_args(t_node **stack, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num < -2147483648 || num > 2147483647)
			return (ft_printf("Error\n"), 0);
		if (check_duplicates(*stack, (int)num))
			return (ft_printf("Error\n"), 0);
		append_node(stack, (int)num);
		i++;
	}
	return (1);
}

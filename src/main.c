/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:37 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/15 18:21:28 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Error\n");
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		value;

	if (argc < 2)
		return (1);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (1);

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (is_valid_number(argv[i]) && !is_duplicate(stack_a, value))
			append_node(stack_a, value);
		else
			cleanup(stack_a, stack_b);
		i++;
	}

	ft_printf("Initial stacks:\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	ft_printf("\nAfter pb (push first to b):\n");
	pb(stack_a, stack_b);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	ft_printf("\nAfter pb (push second to b):\n");
	pb(stack_a, stack_b);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	ft_printf("\nAfter ra (rotate stack a):\n");
	ra(stack_a);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	ft_printf("\nAfter rra (reverse rotate stack a):\n");
	rra(stack_a);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	ft_printf("\nAfter rr (rotate both stacks):\n");
	rr(stack_a, stack_b);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_printf("\nAfter rrr (reverse rotate both stacks):\n");
	rrr(stack_a, stack_b);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}


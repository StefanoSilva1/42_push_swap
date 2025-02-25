/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:37 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/25 17:20:15 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static char	**parse_args(int argc, char **argv)
{
	if (argc == 1)
		return (NULL);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (&argv[1]);
}

static int	fill_stack(t_stack *stack_a, char **args)
{
	int	i;
	int	value;

	i = 0;
	while (args[i])
	{
		value = ft_atoi(args[i]);
		if (!is_valid_number(args[i]) || is_duplicate(stack_a, value))
			return (0);
		append_node(stack_a, value);
		i++;
	}
	return (1);
}

static void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	handle_small_stacks(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	a_to_b(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
	if (!is_sorted(stack_a))
		final_sort(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (1);
	args = parse_args(argc, argv);
	if (!args)
		cleanup(stack_a, stack_b, "");
	if (!fill_stack(stack_a, args))
	{
		if (argc == 2)
			free_array(args);
		cleanup(stack_a, stack_b, "Error\n");
	}
	if (argc == 2)
		free_array(args);
	sort_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// ARG="4 67 3 87 23 0 -1"; ./push_swap $ARG

// ARG=$(seq 100 | shuf | tr '\n' ' ' ); ./push_swap $ARG | wc -l

// ARG="69 31 46 79 5 6 1"; ./push_swap $ARG | ./checker_linux $ARG
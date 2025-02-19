/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:11:17 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/19 04:17:09 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		best_cost;
	int		cost;

	find_targets(stack_a, stack_b);
	calculate_costs(stack_a, stack_b);
	stack_a->cheapest_node = stack_a->top;
	best_cost = stack_a->cheapest_node->cost;
	current = stack_a->top->next;
	while (current)
	{
		cost = current->cost;
		if (cost < best_cost)
		{
			best_cost = cost;
			stack_a->cheapest_node = current;
		}
		current = current->next;
	}
}

void	move_together(t_stack *stack_a, t_stack *stack_b, t_node *cheapest, t_node *target)
{
	int		cost_a;
	int		cost_b;

	cost_a = m_cost(cheapest->index, stack_a->size, cheapest->up_half);
	cost_b = m_cost(target->index, stack_b->size, target->up_half);
	while (cheapest != stack_a->top && target != stack_b->top)
	{
		if (cost_a < cost_b)
		{
			if (cheapest->up_half)
				rr(stack_a, stack_b);
			else
				rrr(stack_a, stack_b);
		}
		else
		{
			if (target->up_half)
				rr(stack_a, stack_b);
			else
				rrr(stack_a, stack_b);
		}
		cost_a = m_cost(cheapest->index, stack_a->size, cheapest->up_half);
		cost_b = m_cost(target->index, stack_b->size, target->up_half);
	}
}

void	move_cheapest_to_top(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*target;
	int		limit;

	if (!stack_a || !stack_a->cheapest_node)
		return ;
	cheapest = stack_a->cheapest_node;
	target = cheapest->target;
	if (!target)
		return ;
	limit = close_limit(stack_a, stack_b);
	if ((cheapest->up_half == target->up_half) || \
		(compute_difference(cheapest->index, target->index) < limit))
		move_together(stack_a, stack_b, cheapest, target);
	move_node_to_top(stack_a, cheapest);
	move_node_to_top(stack_b, target);
	pb(stack_a, stack_b);
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		find_cheapest(stack_a, stack_b);
		move_cheapest_to_top(stack_a, stack_b);
	}
	sort_3(stack_a);
}

void	final_sort(t_stack *stack_a)
{
	t_node	*min;
	t_node	*current;

	if (!stack_a || !stack_a->top || stack_a->size <= 1)
		return ;
	min = stack_a->top;
	current = stack_a->top->next;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	while (stack_a->top != min)
	{
		if (min->up_half)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

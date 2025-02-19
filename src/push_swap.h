/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:45 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/19 10:47:38 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				up_half;
	int				cost;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	t_node	*cheapest_node;
}	t_stack;

void	append_node(t_stack *stack, int value);
void	calculate_costs(t_stack *stack_a, t_stack *stack_b);
int		close_limit(t_stack *stack_a, t_stack *stack_b);
int		compute_difference(int a, int b);
void	cleanup(t_stack *stack_a, t_stack *stack_b, const char *msg);
t_node	*find_target_for_node(t_stack *stack_b, int value);
void	find_targets(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
void	handle_small_stacks(t_stack *stack_a, t_stack *stack_b);
t_stack	*init_stack(void);
int		is_duplicate(t_stack *stack, int value);
int		is_sorted(t_stack *stack);
int		is_valid_number(char *str);
int		m_cost(int index, int size, int up_half);
void	node_cost(t_node *node, t_stack *stack_a, t_stack *stack_b, int close);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	print_stack(t_stack *stack, char stack_name);
void	push(t_stack *src, t_stack *dest);
void	push_remaining_nodes(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	sort_3(t_stack *stack_a);
void	sort_4(t_stack *stack_a, t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	swap_top(t_stack *stack);
void	update_indices(t_stack *stack);
t_node	*find_target_candidate(t_stack *stack_b, int value);
t_node	*find_max_node(t_stack *stack_b);
t_node	*find_min_node(t_stack *stack);
void	find_cheapest(t_stack *stack_a, t_stack *stack_b);
void	move_together(t_stack *stack_a, t_stack *stack_b, \
		t_node *cheapest, t_node *target);
void	move_node_to_top(t_stack *stack, t_node *node);
void	move_cheapest_to_top(t_stack *stack_a, t_stack *stack_b);
void	a_to_b(t_stack *stack_a, t_stack *stack_b);
t_node	*find_target_b(t_stack *stack_a, t_node *node_b);
void	b_to_a(t_stack *stack_a, t_stack *stack_b);
void	final_sort(t_stack *stack_a);
void	handle_args(int argc, char **argv, char **args);
void	process_args(t_stack *stack_a, char **args);
void	free_resources(char **args, t_stack *stack_a, t_stack *stack_b);
void	free_array(char **array);

#endif

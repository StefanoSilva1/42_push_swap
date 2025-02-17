/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:45 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/17 15:44:40 by sdavi-al         ###   ########.fr       */
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
	int				in_first_half;
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
}	t_stack;

t_stack		*init_stack(void);
void		append_node(t_stack *stack, int value);
void		print_stack(t_stack *stack, char stack_name);
void		free_stack(t_stack *stack);
void		cleanup(t_stack *stack_a, t_stack *stack_b);
int			is_valid_number(char *str);
int			is_duplicate(t_stack *stack, int value);
void		swap_top(t_stack *stack);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack *src, t_stack *dest);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		update_indices(t_stack *stack);
void		find_targets(t_stack *stack_a, t_stack *stack_b);
void		calculate_costs(t_stack *stack_a, t_stack *stack_b);
void		update_indices(t_stack *stack);
t_node *	find_target_for_node(t_stack *stack_b, int value);
void		find_targets(t_stack *stack_a, t_stack *stack_b);
void		calculate_costs(t_stack *stack_a, t_stack *stack_b);

#endif




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:24:51 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/11 14:08:21 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	append_node(t_node **stack, int value);
void	print_stack(t_node *stack);
int		check_duplicates(t_node *stack, int value);
int		process_args(t_node **stack, char **argv);
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	remove_top_node(t_node **src);
void	insert_top_node(t_node **dest, t_node *top);
void	push(t_node **dest, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	swap(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	free_stack(t_node **stack);
void	cleanup(t_node **stack_a, t_node **stack_b, int exit_code);

#endif

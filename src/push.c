/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:29:55 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/11 13:10:55 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_top_node(t_node **src)
{
	t_node	*top;
	t_node	*new_top;
	t_node	*last;

	top = *src;
	new_top = top->next;
	if (new_top == top)
		*src = NULL;
	else
	{
		last = top->prev;
		new_top->prev = last;
		last->next = new_top;
		*src = new_top;
	}
}

void	insert_top_node(t_node **dest, t_node *top)
{
	if (!(*dest))
	{
		*dest = top;
		top->next = top;
		top->prev = top;
	}
	else
	{
		top->next = *dest;
		top->prev = (*dest)->prev;
		(*dest)->prev->next = top;
		(*dest)->prev = top;
		*dest = top;
	}
}

void	push(t_node **dest, t_node **src)
{
	t_node	*top;

	if (!src || !(*src))
		return ;
	top = *src;
	remove_top_node(src);
	insert_top_node(dest, top);
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}

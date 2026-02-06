/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:37:54 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/21 15:09:35 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack*a)
{
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	last = a->top;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = a->top;
	a->top->prev = last;
	last->prev = NULL;
	a->top = last;
	write(1, "rra\n", 4);
	bench_count(a->bench, OP_RRA);
}

void	rrb(t_stack*b)
{
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	last = b->top;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = b->top;
	b->top->prev = last;
	last->prev = NULL;
	b->top = last;
	write(1, "rrb\n", 4);
	bench_count(b->bench, OP_RRB);
}

static void	rra_without_write(t_stack*a)
{
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	last = a->top;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = a->top;
	a->top->prev = last;
	last->prev = NULL;
	a->top = last;
}

static void	rrb_without_write(t_stack*b)
{
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	last = b->top;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = b->top;
	b->top->prev = last;
	last->prev = NULL;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra_without_write(a);
	rrb_without_write(b);
	write(1, "rrr\n", 4);
	bench_count(a->bench, OP_RRR);
}

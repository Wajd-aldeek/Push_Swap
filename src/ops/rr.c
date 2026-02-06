/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:37:45 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/21 15:09:39 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack*a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	a->top = first->next;
	a->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
	bench_count(a->bench, OP_RA);
}

void	rb(t_stack*b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	b->top = first->next;
	b->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
	bench_count(b->bench, OP_RB);
}

static void	ra_without_write(t_stack*a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	a->top = first->next;
	a->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

static void	rb_without_write(t_stack*b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	b->top = first->next;
	b->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	ra_without_write(a);
	rb_without_write(b);
	write(1, "rr\n", 3);
	bench_count(a->bench, OP_RR);
}

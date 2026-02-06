/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wal-deek <wal-deek@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:19:54 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/07 11:05:23 by wal-deek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stack*a, t_stack*b)
{
	t_node	*node_to_push;

	if (!b || !b->top)
		return ;
	node_to_push = b->top;
	b->top = node_to_push->next;
	if (b->top)
		b->top->prev = NULL;
	b->size--;
	node_to_push->next = a->top;
	if (a->top)
		a->top->prev = node_to_push;
	a->top = node_to_push;
	node_to_push->prev = NULL;
	a->size++;
	write(1, "pa\n", 3);
	bench_count(a->bench, OP_PA);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wal-deek <wal-deek@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:20:38 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/07 11:07:10 by wal-deek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pb(t_stack*a, t_stack*b)
{
	t_node	*node_to_push;

	if (!a || !a->top)
		return ;
	node_to_push = a->top;
	a->top = node_to_push->next;
	if (a->top)
		a->top->prev = NULL;
	a->size--;
	node_to_push->next = b->top;
	if (b->top)
		b->top->prev = node_to_push;
	b->top = node_to_push;
	node_to_push->prev = NULL;
	b->size++;
	write(1, "pb\n", 3);
	bench_count(a->bench, OP_PB);
}

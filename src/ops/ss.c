/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:37:36 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/21 15:09:07 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack*a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	a->top = second;
	write(1, "sa\n", 3);
	bench_count(a->bench, OP_SA);
}

void	sb(t_stack*b)
{
	t_node	*first;
	t_node	*second;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	b->top = second;
	write(1, "sb\n", 3);
	bench_count(b->bench, OP_SB);
}

static void	sa_without_write(t_stack*a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	a->top = second;
}

static void	sb_without_write(t_stack*b)
{
	t_node	*first;
	t_node	*second;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	b->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	sa_without_write(a);
	sb_without_write(b);
	write(1, "ss\n", 3);
	bench_count(a->bench, OP_SS);
}

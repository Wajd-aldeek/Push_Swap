/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:37:59 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/21 11:58:45 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->top->index > a->top->next->index)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->index;
	y = a->top->next->index;
	z = a->top->next->next->index;
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int		pos;
	t_node	*cur;

	pos = 0;
	cur = a->top;
	while (cur && cur->index != 0)
	{
		pos++;
		cur = cur->next;
	}
	if (pos <= a->size / 2)
		while (a->top->index != 0)
			ra(a);
	else
		while (a->top->index != 0)
			rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	sort_5_extention(t_stack *a, t_stack *b, int idx)
{
	int	pos;

	pos = get_position(a->top, idx);
	if (pos <= a->size / 2)
		while (a->top->index != idx)
			ra(a);
	else
		while (a->top->index != idx)
			rra(a);
	pb(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	sort_5_extention(a, b, 0);
	sort_5_extention(a, b, 1);
	sort_3(a);
	if (b->top->index < b->top->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}

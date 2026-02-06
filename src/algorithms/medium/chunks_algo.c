/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wal-deek <wal-deek@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:01:43 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/07 13:28:25 by wal-deek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_chunks(t_stack*a, t_stack*b)
{
	int	chunk_size;

	make_indexing(a);
	chunk_size = calculate_chunk(a->size);
	push_to_b(a, b, chunk_size);
	back_to_a(a, b);
}

void	push_to_b(t_stack*a, t_stack*b, int chunk_size)
{
	int	i;

	i = 0;
	while (a->top)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->top->index <= (i + chunk_size))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	back_to_a(t_stack*a, t_stack*b)
{
	int	max_idx;

	while (b->top)
	{
		max_idx = get_max_index(b);
		if (get_position(b->top, max_idx) <= b->size / 2)
		{
			while (b->top->index != max_idx)
				rb(b);
		}
		else
		{
			while (b->top->index != max_idx)
				rrb(b);
		}
		pa(a, b);
	}
}

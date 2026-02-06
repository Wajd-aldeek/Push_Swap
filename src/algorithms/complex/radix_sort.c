/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wal-deek <wal-deek@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:18:54 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/17 14:18:58 by wal-deek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	max_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_node	*tmp;

	tmp = a->top;
	max = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		size;
	int		bits;

	bits = max_bits(a);
	i = 0;
	while (i < bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

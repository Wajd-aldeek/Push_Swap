/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:18:47 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/17 22:23:54 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_stack(t_stack*a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		rra(a);
		i++;
	}
}

void	bubble_sort(t_stack*a, t_stack*b)
{
	int	i;
	int	swapped;

	(void)b;
	if (!a || a->size < 2)
		return ;
	while (1)
	{
		i = 0;
		swapped = 0;
		while (i < a->size - 1)
		{
			if (a->top->value > a->top->next->value)
			{
				sa(a);
				swapped = 1;
			}
			ra(a);
			i++;
		}
		reset_stack(a);
		if (!swapped)
			break ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:18:32 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/17 22:58:32 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node		*i;
	t_node		*j;
	long		mistakes;
	long		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

static int	handle_small_sorts(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		return (0);
	if (a->bench)
	{
		a->bench->used = STRAT_ADAPTIVE;
		a->bench->class_name = "O(1)";
	}
	return (1);
}

static void	set_adaptive_bench(t_stack *a, double disorder, const char *class)
{
	if (!a->bench)
		return ;
	a->bench->disorder = disorder;
	a->bench->used = STRAT_ADAPTIVE;
	a->bench->class_name = class;
}

static void	run_adaptive(t_stack *a, t_stack *b)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
	{
		set_adaptive_bench(a, disorder, "O(n)");
		bubble_sort(a, b);
	}
	else if (disorder < 0.5)
	{
		set_adaptive_bench(a, disorder, "O(n*sqrt(n))");
		push_swap_chunks(a, b);
	}
	else
	{
		set_adaptive_bench(a, disorder, "O(n*log(n))");
		radix_sort(a, b);
	}
}

void	sort_dispatcher(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (handle_small_sorts(a, b))
		return ;
	run_adaptive(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:37:19 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/18 23:37:20 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inc(t_bench *bench, long *x)
{
	if (!bench || !bench->enabled)
		return ;
	(*x)++;
	bench->total++;
}

void	bench_count(t_bench *bench, t_op op)
{
	if (op == OP_SA)
		inc(bench, &bench->sa);
	else if (op == OP_SB)
		inc(bench, &bench->sb);
	else if (op == OP_SS)
		inc(bench, &bench->ss);
	else if (op == OP_PA)
		inc(bench, &bench->pa);
	else if (op == OP_PB)
		inc(bench, &bench->pb);
	else if (op == OP_RA)
		inc(bench, &bench->ra);
	else if (op == OP_RB)
		inc(bench, &bench->rb);
	else if (op == OP_RR)
		inc(bench, &bench->rr);
	else if (op == OP_RRA)
		inc(bench, &bench->rra);
	else if (op == OP_RRB)
		inc(bench, &bench->rrb);
	else if (op == OP_RRR)
		inc(bench, &bench->rrr);
}

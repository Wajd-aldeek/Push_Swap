/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:38:52 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/18 23:38:53 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_percent(double ratio)
{
	long	p;

	p = (long)(ratio * 10000.0 + 0.5);
	putnbr_fd(p / 100, 2);
	putstr_fd(".", 2);
	if ((p % 100) < 10)
		putstr_fd("0", 2);
	putnbr_fd(p % 100, 2);
	putstr_fd("%\n", 2);
}

static void	print_strategy(t_bench *bench)
{
	putstr_fd("strategy: ", 2);
	if (bench->used == STRAT_SIMPLE)
		putstr_fd("simple", 2);
	else if (bench->used == STRAT_MEDIUM)
		putstr_fd("medium", 2);
	else if (bench->used == STRAT_COMPLEX)
		putstr_fd("complex", 2);
	else
		putstr_fd("adaptive", 2);
	putstr_fd("\nclass: ", 2);
	putstr_fd(bench->class_name, 2);
	putstr_fd("\n", 2);
}

static void	print_counts_line1(t_bench *bench)
{
	putstr_fd("ops: ", 2);
	putnbr_fd(bench->total, 2);
	putstr_fd("\nsa ", 2);
	putnbr_fd(bench->sa, 2);
	putstr_fd(" sb ", 2);
	putnbr_fd(bench->sb, 2);
	putstr_fd(" ss ", 2);
	putnbr_fd(bench->ss, 2);
	putstr_fd("\npa ", 2);
	putnbr_fd(bench->pa, 2);
	putstr_fd(" pb ", 2);
	putnbr_fd(bench->pb, 2);
	putstr_fd("\n", 2);
}

static void	print_counts_line2(t_bench *bench)
{
	putstr_fd("ra ", 2);
	putnbr_fd(bench->ra, 2);
	putstr_fd(" rb ", 2);
	putnbr_fd(bench->rb, 2);
	putstr_fd(" rr ", 2);
	putnbr_fd(bench->rr, 2);
	putstr_fd("\nrra ", 2);
	putnbr_fd(bench->rra, 2);
	putstr_fd(" rrb ", 2);
	putnbr_fd(bench->rrb, 2);
	putstr_fd(" rrr ", 2);
	putnbr_fd(bench->rrr, 2);
	putstr_fd("\n", 2);
}

void	bench_print(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	putstr_fd("disorder: ", 2);
	print_percent(bench->disorder);
	print_strategy(bench);
	print_counts_line1(bench);
	print_counts_line2(bench);
}

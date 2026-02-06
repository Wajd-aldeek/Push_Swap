/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wal-deek <wal-deek@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:19:43 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/18 20:45:00 by wal-deek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *s, t_bench *bench)
{
	s->top = NULL;
	s->size = 0;
	s->bench = bench;
}

static int	parse_and_build(t_stack *a, t_bench *bench, int ac, char **av)
{
	int	start;

	if (!parse_flags(bench, ac, av, &start))
		error_exit(a);
	if (start >= ac)
		return (0);
	if (!av[start][0] || !validate_args_from(av, start))
		error_exit(a);
	init_stack_a_from(a, av, start);
	if (!a->top)
		error_exit(a);
	return (1);
}

static void	run_forced(t_stack *a, t_stack *b)
{
	if (a->bench->forced == STRAT_SIMPLE)
		bubble_sort(a, b);
	else if (a->bench->forced == STRAT_MEDIUM)
		push_swap_chunks(a, b);
	else if (a->bench->forced == STRAT_COMPLEX)
		radix_sort(a, b);
	else
		sort_dispatcher(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;

	init_stack(&a, &bench);
	init_stack(&b, &bench);
	if (argc < 2)
		return (0);
	if (!parse_and_build(&a, &bench, argc, argv))
		return (0);
	make_indexing(&a);
	if (bench.enabled)
		bench.disorder = compute_disorder(&a);
	run_forced(&a, &b);
	bench_print(&bench);
	free_stack(&b);
	free_stack(&a);
	return (0);
}

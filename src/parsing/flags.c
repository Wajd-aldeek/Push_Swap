/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:37:11 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/18 23:37:13 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	streq(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == 0 && b[i] == 0);
}

int	parse_flags(t_bench *bench, int argc, char **argv, int *start)
{
	int	i;

	i = 1;
	*bench = (t_bench){0};
	bench->forced = STRAT_ADAPTIVE;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (streq(argv[i], "--bench"))
			bench->enabled = 1;
		else if (streq(argv[i], "--simple"))
			bench->forced = STRAT_SIMPLE;
		else if (streq(argv[i], "--medium"))
			bench->forced = STRAT_MEDIUM;
		else if (streq(argv[i], "--complex"))
			bench->forced = STRAT_COMPLEX;
		else if (streq(argv[i], "--adaptive"))
			bench->forced = STRAT_ADAPTIVE;
		else
			return (0);
		i++;
	}
	*start = i;
	return (1);
}

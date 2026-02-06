/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:18:02 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/21 12:18:27 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_indexing(t_stack *a)
{
	int		*sorted_tmp;
	int		i;
	t_node	*current;

	sorted_tmp = stack_to_sorted_array(a);
	if (!sorted_tmp)
		error_exit(a);
	check_dup(sorted_tmp, a->size, a);
	current = a->top;
	while (current)
	{
		i = 0;
		while (i < a->size)
		{
			if (current->value == sorted_tmp[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(sorted_tmp);
}

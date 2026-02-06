/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:18:45 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/21 12:18:48 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(int *array, int size, t_stack *a)
{
	int	i;

	if (size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (array[i] == array[i + 1])
		{
			free(array);
			error_exit(a);
		}
		i++;
	}
}

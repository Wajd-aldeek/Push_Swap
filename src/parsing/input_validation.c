/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:19:28 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/21 11:59:54 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char**str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	is_number(char*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_args_from(char **argv, int start)
{
	int		i;
	int		j;
	char	**temp;

	i = start;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp || !temp[0])
		{
			free_split(temp);
			return (0);
		}
		j = 0;
		while (temp[j])
		{
			if (!is_number(temp[j]))
				return (free_split(temp), 0);
			j++;
		}
		free_split(temp);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack*a)
{
	int			i;
	t_node		*c;

	i = 0;
	c = a->top;
	while (i < a->size - 1)
	{
		if (c->value > c->next->value)
			return (0);
		i++;
		c = c->next;
	}
	return (1);
}

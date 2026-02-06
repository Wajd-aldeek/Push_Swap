/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:38:18 by raaalali          #+#    #+#             */
/*   Updated: 2026/01/18 23:38:20 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	stack_add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!stack->top)
		stack->top = new;
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	stack->size++;
}

static void	process_and_add(t_stack *a, char *str, char **temp_args)
{
	long	value;
	t_node	*new_node;

	value = ft_atoi(str);
	if (value < -2147483648 || value > 2147483647)
	{
		free_split(temp_args);
		error_exit(a);
	}
	new_node = get_new_node((int)value);
	if (!new_node)
	{
		free_split(temp_args);
		error_exit(a);
	}
	stack_add_back(a, new_node);
}

void	init_stack_a_from(t_stack *a, char **argv, int start)
{
	int		i;
	int		j;
	char	**temp_args;

	i = start;
	while (argv[i])
	{
		temp_args = ft_split(argv[i], ' ');
		if (!temp_args)
			error_exit(a);
		j = 0;
		while (temp_args[j])
		{
			process_and_add(a, temp_args[j], temp_args);
			j++;
		}
		free_split(temp_args);
		i++;
	}
}

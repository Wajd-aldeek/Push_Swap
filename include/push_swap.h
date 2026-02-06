/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:21:15 by wal-deek          #+#    #+#             */
/*   Updated: 2026/01/21 12:38:14 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_bench	t_bench;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	t_bench	*bench;
}	t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_bench
{
	int			enabled;
	t_strategy	forced;
	t_strategy	used;
	const char	*class_name;
	double		disorder;
	long		total;
	long		sa;
	long		sb;
	long		ss;
	long		pa;
	long		pb;
	long		ra;
	long		rb;
	long		rr;
	long		rra;
	long		rrb;
	long		rrr;
}	t_bench;

void	sa(t_stack*a);
//(swap a): Swap the first two elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	sb(t_stack*b);
//(swap b): Swap the first two elements at the top of stack b.
//Do nothing if there is only one or no elements.
void	ss(t_stack*a, t_stack*b);
//sa and sb at the same time.
void	pa(t_stack*a, t_stack*b);
//(push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void	pb(t_stack*a, t_stack*b);
//(push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
void	ra(t_stack*a);
//(rotate a): Shift up all elements of stack a by one.
//The first element becomes the last one.
void	rb(t_stack*b);
//(rotate b): Shift up all elements of stack b by one.
//The first element becomes the last one.
void	rr(t_stack*a, t_stack*b);
//ra and rb at the same time.
void	rra(t_stack*a);
//(reverse rotate a): Shift down all elements of stack a by one.
//The last element becomes the first one.
void	rrb(t_stack*b);
//(reverse rotate b): Shift down all elements of stack b by one.
//The last element becomes the first one.
void	rrr(t_stack*a, t_stack*b);
//rra and rrb at the same time.
void	init_stack_a_from(t_stack *a, char **argv, int start);
int		validate_args_from(char **argv, int start);
void	free_stack(t_stack*stack);
void	free_split(char**str);
void	error_exit(t_stack *stack);
void	push_swap_chunks(t_stack*a, t_stack*b);
void	push_to_b(t_stack*a, t_stack*b, int chunk_size);
void	back_to_a(t_stack*a, t_stack*b);
void	bubble_sort(t_stack*a, t_stack*b);
void	radix_sort(t_stack*a, t_stack*b);
int		get_position(t_node*top, int target_index);
int		calculate_chunk(int size);
int		get_max_index(t_stack*s);
void	make_indexing(t_stack*a);
void	sort_dispatcher(t_stack *a, t_stack *b);
double	compute_disorder(t_stack *a);
char	**ft_split(const char *s, char c);
long	ft_atoi(const char *str);
int		is_sorted(t_stack*a);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
int		parse_flags(t_bench *bench, int argc, char **argv, int *start);
void	putstr_fd(const char *s, int fd);
void	putnbr_fd(long n, int fd);
void	bench_print(t_bench *bench);
void	bench_count(t_bench *bench, t_op op);
int		*stack_to_sorted_array(t_stack *a);
void	check_dup(int *array, int size, t_stack *a);
#endif

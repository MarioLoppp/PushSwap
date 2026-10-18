/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:09 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 17:34:16 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <strings.h>

static void	init_count(t_mvlst *moves)
{
	moves->count.sa = 0;
	moves->count.sb = 0;
	moves->count.ss = 0;
	moves->count.pa = 0;
	moves->count.pb = 0;
	moves->count.ra = 0;
	moves->count.rb = 0;
	moves->count.rr = 0;
	moves->count.rra = 0;
	moves->count.rrb = 0;
	moves->count.rrr = 0;
}

static void	mvlst_init(t_mvlst *moves)
{
	moves->top = NULL;
	moves->bottom = NULL;
	moves->size = 0;
	init_count(moves);
}

static void	stack_init(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
}

static int	execute_algo(t_stack *a, t_stack *b, t_parse flags)
{
	t_mvlst	moves;
	int		disorder;

	disorder = disorder_index(a);
	mvlst_init(&moves);
	if (!is_sorted(a))
	{
		if (flags.algo == 1)
			bubble_sort(a, b, &moves);
		if (flags.algo == 2)
			sort_medium(a, b, &moves);
		if (flags.algo == 3)
			radix_sort(a, b, &moves);
		if (flags.algo == 4 || flags.algo == 0)
			adaptive(a, b, &moves, disorder);
	}
	if (flags.bench)
		print_bench(disorder, flags, moves);
	return (free_moves(&moves), 0);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_parse	flags;

	if (ac < 2)
		return (0);
	stack_init(&stack_a, 'a');
	stack_init(&stack_b, 'b');
	if (parse_flags(ac, av, &flags) == -1)
		return (ft_error(), 2);
	if (parse_ints(ac, av, &stack_a) == -1)
		return (free_stack(&stack_a), ft_error(), 2);
	if (stack_a.size == 0)
		return (free_stack(&stack_a), 0);
	lstindex(&stack_a);
	execute_algo(&stack_a, &stack_b, flags);
	free_stack(&stack_a);
	return (0);
}

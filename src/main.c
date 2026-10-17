/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:09 by salegari          #+#    #+#             */
/*   Updated: 2026/10/17 20:43:05 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <strings.h>

void	init_count(t_mvlst *moves)
{
	moves->count.sa = 0;
	moves->count.sb = 0;
	moves->count.ss = 0;
	moves->count.pa = 0;
	moves->count.pa = 0;
	moves->count.ra = 0;
	moves->count.rb = 0;
	moves->count.rr = 0;
	moves->count.rra = 0;
	moves->count.rrb = 0;
	moves->count.rrr = 0;
}

void	mvlst_init(t_mvlst *moves)
{
	moves->top = NULL;
	moves->bottom = NULL;
	moves->size = 0;
	init_count(moves);
}

void	stack_init(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
}

int	execute_algo(t_stack *a, t_stack *b, t_parse flags)
{
	t_mvlst	moves;
	int		disorder;

	disorder = disorder_index(a);
	mvlst_init(&moves);
	if (flags.algo == 1)
		bubble_sort(a, b, &moves);
	if (flags.algo == 2)
		sort_medium(a, b, &moves);
	if (flags.algo == 3)
		radix_sort(a, b, &moves);
	// if (flags.algo == 4)
	// 	adaptative(a, b, &moves);
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
	{
		ft_printf("Error\n");
		exit(2);
	}
	stack_init(&stack_a, 'a');
	stack_init(&stack_b, 'b');
	parse_flags(ac, av, &flags);
	if (!parse_ints(ac, av, &stack_a, flags))
		return (free_stack(&stack_a), ft_error(), 2);
	lstindex(&stack_a);
	execute_algo(&stack_a, &stack_b, flags);
	free_stack(&stack_a);
	return (1);
}

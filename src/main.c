/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:09 by salegari          #+#    #+#             */
/*   Updated: 2026/10/14 20:46:56 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <strings.h>

int	execute_algo(t_stack *a, t_stack *b, t_parse flags)
{
	if (flags.algo == 1)
		bubble_sort(a, b);
	if (flags.algo == 2)
		sort_medium(a, b);
	if (flags.algo == 3)
		radix_sort(a, b);
	if (flags.bench)
		print_bench(a, b);
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
	parse_flags(ac, av, &flags);
	if (!parse_ints(ac, av, &stack_a, flags))
		return (free_stack(&stack_a), ft_error());
	lstindex(&stack_a);
	execute_algo(&stack_a, &stack_b, flags);
}

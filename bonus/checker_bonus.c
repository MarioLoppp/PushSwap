/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:16:16 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/18 17:52:43 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	check_result(t_stack *a, t_stack *b)
{
	if (read_moves(a, b) == -1)
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_parse	flags;
	int		result;

	if (argc < 2)
		return (0);
	stack_init(&a, 'a');
	stack_init(&b, 'b');
	flags.algo = 0;
	flags.bench = 0;
	if (parse_ints(argc, argv, &a, flags) == -1)
		return (free_stack(&a), write(2, "Error\n", 6), 1);
	lstindex(&a);
	result = check_result(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (result);
}

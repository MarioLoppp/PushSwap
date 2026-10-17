/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:16:39 by salegari          #+#    #+#             */
/*   Updated: 2026/10/17 22:11:16 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*set_strat(int algo)
{
	if (algo == 1)
		return ("Simple / O(n^2)");
	if (algo == 2)
		return ("Medium / O(n√n)");
	if (algo == 3)
		return ("Complex / O(n log n)");
	if (algo == 4)
		return ("Adaptative / "); // DEFINIR FUNCION ALGORITMO
	return (NULL);
}

void	print_bench(int disorder, t_parse flags, t_mvlst moves)
{
	char	*strat;
	int		ent;
	int		dec;

	strat = set_strat(flags.algo);
	ent = disorder / 100;
	dec = disorder % 100;
	ft_printf("[bench] disorder: %d.", ent);
	if (dec < 10)
		ft_printf("0");
	ft_printf("%d%%\n", dec);
	ft_printf("[bench] strategy: %s\n", strat);
	ft_printf("[bench] total_ops: %d\n", moves.size);
	ft_printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		moves.count.sa, moves.count.sb, moves.count.ss, moves.count.pa,
		moves.count.pb);
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		moves.count.ra, moves.count.rb, moves.count.rr, moves.count.rra,
		moves.count.rrb, moves.count.rrr);
}

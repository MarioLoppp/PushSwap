/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:16:39 by salegari          #+#    #+#             */
/*   Updated: 2026/10/17 23:50:22 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_moves(t_mvlst moves)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(moves.count.sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(moves.count.sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(moves.count.ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(moves.count.pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(moves.count.pb, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ra:  ", 2);
	ft_putnbr_fd(moves.count.ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(moves.count.rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(moves.count.rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(moves.count.rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(moves.count.rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(moves.count.rrr, 2);
	ft_putchar_fd('\n', 2);
}

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
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(ent, 2);
	ft_putchar_fd('.', 2);
	if (dec < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(strat, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(moves.size, 2);
	ft_putchar_fd('\n', 2);
	put_moves(moves);
}

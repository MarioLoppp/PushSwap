/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:16:39 by salegari          #+#    #+#             */
/*   Updated: 2026/10/15 19:28:19 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_bench(t_stack *a, t_stack *b, t_parse flags)
{
	ft_printf("[bench] disorder: %f%%\n", disorder_index(a));
	a = b;
	if (flags.algo == 1)
		return ;
}

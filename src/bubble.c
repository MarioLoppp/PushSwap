/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:13:25 by salegari          #+#    #+#             */
/*   Updated: 2026/10/16 19:56:55 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(t_stack *a, t_stack *b, t_mvlst *moves)
{
	if (!a || !b || b->top)
		return ;
	while (!is_sorted(a))
	{
		while (a->top && a->top->next)
		{
			if (a->top->n > a->top->next->n)
				sa(a, moves, 0);
			pb(a, b, moves);
		}
		while (b->top)
			pa(a, b, moves);
	}
}

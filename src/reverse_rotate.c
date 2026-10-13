/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:48:31 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 19:23:47 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_stack *a)
{
	t_nums	*last;

	if (!a || !a->top || !a->top->next)
		return (0);
	last = a->bottom;
	a->bottom = last->prev;
	a->bottom->next = NULL;
	last->prev = NULL;
	last->next = a->top;
	a->top->prev = last;
	a->top = last;
	return (1);
}

int	rrb(t_stack *b)
{
	t_nums	*last;

	if (!b || !b->top || !b->top->next)
		return (0);
	last = b->bottom;
	b->bottom = last->prev;
	b->bottom->next = NULL;
	last->prev = NULL;
	last->next = b->top;
	b->top->prev = last;
	b->top = last;
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = rra(a);
	moved_b = rrb(b);
	return (moved_a || moved_b);
}

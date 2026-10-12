/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:49:19 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 19:23:15 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_stack *a)
{
	t_nums	*first;

	if (!a || !a->top || !a->top->next)
		return (0);
	first = a->top;
	a->top = first->next;
	a->top->prev = NULL;
	first->prev = a->bottom;
	first->next = NULL;
	a->bottom->next = first;
	a->bottom = first;
	return (1);
}

int	rb(t_stack *b)
{
	t_nums	*first;

	if (!b || !b->top || !b->top->next)
		return (0);
	first = b->top;
	b->top = first->next;
	b->top->prev = NULL;
	first->prev = b->bottom;
	first->next = NULL;
	b->bottom->next = first;
	b->bottom = first;
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = ra(a);
	moved_b = rb(b);
	return (moved_a || moved_b);
}

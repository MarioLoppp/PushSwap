/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:22:13 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 19:22:56 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_stack *a)
{
	t_nums	*first;
	t_nums	*second;

	if (!a || !a->top || !a->top->next)
		return (0);
	first = a->top;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	else
		a->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	a->top = second;
	return (1);
}

int	sb(t_stack *b)
{
	t_nums	*first;
	t_nums	*second;

	if (!b || !b->top || !b->top->next)
		return (0);
	first = b->top;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	else
		b->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	b->top = second;
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = sa(a);
	moved_b = sb(b);
	return (moved_a || moved_b);
}

int	pa(t_stack *a, t_stack *b)
{
	t_nums	*first;

	if (!a || !b || a == b || !b->top)
		return (0);
	first = b->top;
	b->top = first->next;
	if (b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	first->prev = NULL;
	first->next = a->top;
	if (a->top)
		a->top->prev = first;
	else
		a->bottom = first;
	a->top = first;
	b->size--;
	a->size++;
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	t_nums	*first;

	if (!b || !a || a == b || !a->top)
		return (0);
	first = a->top;
	a->top = first->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	first->prev = NULL;
	first->next = b->top;
	if (b->top)
		b->top->prev = first;
	else
		b->bottom = first;
	b->top = first;
	a->size--;
	b->size++;
	return (1);
}

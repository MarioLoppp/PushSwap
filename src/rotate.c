/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:49:19 by salegari          #+#    #+#             */
/*   Updated: 2026/10/16 21:38:01 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_stack *a, t_mvlst *moves, int flag)
{
	t_nums	*first;
	t_move	*new;

	if (!a || !a->top || !a->top->next)
		return (0);
	first = a->top;
	a->top = first->next;
	a->top->prev = NULL;
	first->prev = a->bottom;
	first->next = NULL;
	a->bottom->next = first;
	a->bottom = first;
	new = move_new("ra");
	ft_printf("ra\n");
	if (!flag)
	{
		moves_add_back(moves, new);
		return (moves->count.ra++, 1);
	}
	return (free(new), 1);
}

int	rb(t_stack *b, t_mvlst *moves, int flag)
{
	t_nums	*first;
	t_move	*new;

	if (!b || !b->top || !b->top->next)
		return (0);
	first = b->top;
	b->top = first->next;
	b->top->prev = NULL;
	first->prev = b->bottom;
	first->next = NULL;
	b->bottom->next = first;
	b->bottom = first;
	new = move_new("rb");
	moves_add_back(moves, new);
	ft_printf("rb\n");
	if (!flag)
	{
		moves_add_back(moves, new);
		return (moves->count.rb++, 1);
	}
	return (free(new), 1);
}

int	rr(t_stack *a, t_stack *b, t_mvlst *moves)
{
	int		moved_a;
	int		moved_b;
	t_move	*new;

	moved_a = ra(a, moves, 1);
	moved_b = rb(b, moves, 1);
	new = move_new("rr");
	moves_add_back(moves, new);
	moves->count.rr++;
	ft_printf("rr\n");
	return (moved_a || moved_b);
}

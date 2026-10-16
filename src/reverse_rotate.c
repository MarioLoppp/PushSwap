/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:48:31 by salegari          #+#    #+#             */
/*   Updated: 2026/10/16 21:38:21 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_stack *a, t_mvlst *moves, int flag)
{
	t_nums	*last;
	t_move	*new;

	if (!a || !a->top || !a->top->next)
		return (0);
	last = a->bottom;
	a->bottom = last->prev;
	a->bottom->next = NULL;
	last->prev = NULL;
	last->next = a->top;
	a->top->prev = last;
	a->top = last;
	new = move_new("rra");
	ft_printf("rra\n");
	if (!flag)
	{
		moves_add_back(moves, new);
		return (moves->count.rra++, 1);
	}
	return (free(new), 1);
}

int	rrb(t_stack *b, t_mvlst *moves, int flag)
{
	t_nums	*last;
	t_move	*new;

	if (!b || !b->top || !b->top->next)
		return (0);
	last = b->bottom;
	b->bottom = last->prev;
	b->bottom->next = NULL;
	last->prev = NULL;
	last->next = b->top;
	b->top->prev = last;
	b->top = last;
	new = move_new("rrb");
	ft_printf("rrb\n");
	if (!flag)
	{
		moves_add_back(moves, new);
		return (moves->count.rrb++, 1);
	}
	return (free(new), 1);
}

int	rrr(t_stack *a, t_stack *b, t_mvlst *moves)
{
	int		moved_a;
	int		moved_b;
	t_move	*new;

	moved_a = rra(a, moves, 1);
	moved_b = rrb(b, moves, 1);
	new = move_new("rrr");
	moves_add_back(moves, new);
	moves->count.rrr++;
	ft_printf("rrr\n");
	return (moved_a || moved_b);
}

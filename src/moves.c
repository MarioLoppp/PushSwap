/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:22:13 by salegari          #+#    #+#             */
/*   Updated: 2026/10/16 21:37:44 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_stack *a, t_mvlst *moves, int flag)
{
	t_nums	*first;
	t_nums	*second;
	t_move	*new;

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
	new = move_new("sa");
	ft_printf("sa\n");
	if (!flag)
	{
		moves_add_back(moves, new);
		return (moves->count.sa++, 1);
	}
	return (free(new), 1);
}

int	sb(t_stack *b, t_mvlst *moves, int flag)
{
	t_nums	*first;
	t_nums	*second;
	t_move	*new;

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
	new = move_new("sb");
	ft_printf("sb\n");
	if (!flag)
	{
		moves_add_back(moves, new);
		return (moves->count.sb++, 1);
	}
	return (free(new), 1);
}

int	ss(t_stack *a, t_stack *b, t_mvlst *moves)
{
	int		moved_a;
	int		moved_b;
	t_move	*new;

	moved_a = sa(a, moves, 1);
	moved_b = sb(b, moves, 1);
	new = move_new("ss");
	moves_add_back(moves, new);
	moves->count.ss++;
	ft_printf("ss\n");
	return (moved_a || moved_b);
}

int	pa(t_stack *a, t_stack *b, t_mvlst *moves)
{
	t_nums	*first;
	t_move	*new;

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
	new = move_new("pa");
	moves_add_back(moves, new);
	ft_printf("pa\n");
	return (moves->count.pa++, 1);
}

int	pb(t_stack *a, t_stack *b, t_mvlst *moves)
{
	t_nums	*first;
	t_move	*new;

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
	new = move_new("pb");
	moves_add_back(moves, new);
	ft_printf("pb\n");
	return (moves->count.pb++, 1);
}

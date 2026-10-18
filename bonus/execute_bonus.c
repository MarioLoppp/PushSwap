/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:00:00 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/18 12:00:00 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return (0);
	tmp = s->top->n;
	s->top->n = s->top->next->n;
	s->top->next->n = tmp;
	tmp = s->top->index;
	s->top->index = s->top->next->index;
	s->top->next->index = tmp;
	return (0);
}

static int	push(t_stack *to, t_stack *from)
{
	t_nums	*node;

	if (!from->top)
		return (0);
	node = from->top;
	from->top = node->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	node->prev = NULL;
	node->next = to->top;
	if (to->top)
		to->top->prev = node;
	else
		to->bottom = node;
	to->top = node;
	to->size++;
	return (0);
}

static int	rotate(t_stack *s, int reverse)
{
	if (s->size < 2)
		return (0);
	s->top->prev = s->bottom;
	s->bottom->next = s->top;
	if (reverse)
	{
		s->top = s->bottom;
		s->bottom = s->bottom->prev;
	}
	else
	{
		s->bottom = s->top;
		s->top = s->top->next;
	}
	s->top->prev = NULL;
	s->bottom->next = NULL;
	return (0);
}

static int	execute_rotate(char *op, t_stack *a, t_stack *b)
{
	if (same_op(op, "ra"))
		return (rotate(a, 0));
	if (same_op(op, "rb"))
		return (rotate(b, 0));
	if (same_op(op, "rr"))
		return (rotate(a, 0), rotate(b, 0));
	if (same_op(op, "rra"))
		return (rotate(a, 1));
	if (same_op(op, "rrb"))
		return (rotate(b, 1));
	if (same_op(op, "rrr"))
		return (rotate(a, 1), rotate(b, 1));
	return (-1);
}

int	execute_move(char *op, t_stack *a, t_stack *b)
{
	if (same_op(op, "sa"))
		return (swap(a));
	if (same_op(op, "sb"))
		return (swap(b));
	if (same_op(op, "ss"))
		return (swap(a), swap(b));
	if (same_op(op, "pa"))
		return (push(a, b));
	if (same_op(op, "pb"))
		return (push(b, a));
	return (execute_rotate(op, a, b));
}

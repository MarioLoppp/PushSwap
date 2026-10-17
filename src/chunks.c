/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:42:19 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/18 01:31:36 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chunk_size(int n)
{
	int	i;

	i = 0;
	while ((long long)i * i < n)
		i++;
	return (i);
}

void	push_chunk(t_stack *a, t_stack *b, int *range, t_mvlst *moves)
{
	int	i;

	i = a->size;
	while (i > 0)
	{
		if (a->top->index >= range[0] && a->top->index < range[1])
			pb(a, b, moves);
		else
			ra(a, moves, 0);
		i--;
	}
}

int	max_position(t_stack *b)
{
	int		i;
	t_nums	*temp;
	int		max_index;
	int		max_position;

	if (!b->top)
		return (-1);
	temp = b->top;
	i = 0;
	max_index = temp->index;
	max_position = 0;
	while (temp)
	{
		if (temp->index > max_index)
		{
			max_index = temp->index;
			max_position = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_position);
}

void	pull_max(t_stack *a, t_stack *b, t_mvlst *mvs)
{
	int	pos;
	int	moves;

	pos = max_position(b);
	if (pos <= b->size / 2)
	{
		moves = pos;
		while (moves > 0)
		{
			rb(b, mvs, 0);
			moves--;
		}
	}
	else
	{
		moves = b->size - pos;
		while (moves > 0)
		{
			rrb(b, mvs, 0);
			moves--;
		}
	}
	pa(a, b, mvs);
}

void	sort_medium(t_stack *a, t_stack *b, t_mvlst *moves)
{
	int	total;
	int	chunk;
	int	range[2];

	if (!a || !b)
		return ;
	if (b->size || is_sorted(a))
		return ;
	total = a->size;
	chunk = chunk_size(total);
	range[0] = 0;
	while (range[0] < total)
	{
		range[1] = range[0] + chunk;
		push_chunk(a, b, range, moves);
		range[0] += chunk;
	}
	while (b->size > 0)
		pull_max(a, b, moves);
}

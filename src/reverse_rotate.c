/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:48:31 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 18:02:51 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_nums **a)
{
	t_nums	*last;
	t_nums	*prev;

	if (!a || !*a || !(*a)->next)
		return (0);
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	return (1);
}

int	rrb(t_nums **b)
{
	t_nums	*last;
	t_nums	*prev;

	if (!b || !*b || !(*b)->next)
		return (0);
	prev = *b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *b;
	*b = last;
	return (1);
}

int	rrr(t_nums **a, t_nums **b)
{
	if (!rra(&*a) || !rrb(&*b))
		return (0);
	return (1);
}

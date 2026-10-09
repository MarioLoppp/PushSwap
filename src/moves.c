/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:22:13 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 18:03:26 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_nums **a)
{
	t_nums	*tmp;

	if (!a || !*a || !(*a)->next)
		return (0);
	tmp = *a;
	*a = (*a)->next;
	(*a)->next = tmp;
	return (1);
}

int	sb(t_nums **b)
{
	t_nums	*tmp;

	if (!b || !*b || !(*b)->next)
		return (0);
	tmp = *b;
	*b = (*b)->next;
	(*b)->next = tmp;
	return (1);
}

int	ss(t_nums **a, t_nums **b)
{
	sa(&*a);
	sb(&*b);
	return (1);
}

int	pa(t_nums **a, t_nums **b)
{
	t_nums	*first;

	if (!a || !b || !*b)
		return (0);
	first = *b;
	*b = first->next;
	first->next = *a;
	*a = first;
	return (1);
}

int	pb(t_nums **a, t_nums **b)
{
	t_nums	*first;

	if (!b || !a || !*a)
		return (0);
	first = *a;
	*a = first->next;
	first->next = *b;
	*b = first;
	return (1);
}

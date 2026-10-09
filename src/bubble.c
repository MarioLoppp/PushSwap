/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:13:25 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 19:22:11 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(t_stack **a, t_stack **b)
{
	if (!a || !b || *b)
		return ;
	while (!is_sorted(*a))
	{
		while (*a && (*a)->next)
		{
			if ((*a)->n > (*a)->next->n)
				sa(a);
			pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}

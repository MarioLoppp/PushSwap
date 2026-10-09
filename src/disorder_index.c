/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:30:00 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 19:22:37 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	disorder_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;
	long	inversions;
	long	total_pairs;

	inversions = 0;
	total_pairs = 0;
	current = stack;
	while (current)
	{
		next = current->next;
		while (next)
		{
			total_pairs++;
			if (current->idx > next->idx)
				inversions++;
			next = next->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((inversions * 100) / total_pairs);
}

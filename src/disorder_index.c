/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:30:00 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 18:48:22 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	disorder_index(t_nums *stack)
{
	t_nums	*current;
	t_nums	*next;
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

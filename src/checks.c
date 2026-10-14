/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:50:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/14 20:40:57 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	repeated(t_stack *stack)
{
	t_nums	*current;
	t_nums	*compare;

	if (!stack)
		return (1);
	current = stack->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->n == compare->n)
				return (-1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_nums	*node;

	if (!stack)
		return (1);
	node = stack->top;
	while (node && node->next)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

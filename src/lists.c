/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 20:04:21 by salegari          #+#    #+#             */
/*   Updated: 2026/10/14 20:04:51 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_add_back(t_stack *stack, t_nums *new)
{
	if (!stack || !new)
		return ;
	new->next = NULL;
	new->prev = stack->bottom;
	if (!stack->top)
		stack->top = new;
	else
		stack->bottom->next = new;
	stack->bottom = new;
	stack->size++;
}

t_nums	*num_new(int n)
{
	t_nums	*new;

	new = ft_calloc(1, sizeof(t_nums));
	if (!new)
		return (NULL);
	new->n = n;
	new->index = -1;
	return (new);
}

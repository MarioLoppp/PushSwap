/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:26:47 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 19:32:36 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

void	lstindex(t_stack *stack)
{
	t_nums	*current;
	t_nums	*other;
	int		i;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		i = 0;
		other = stack->top;
		while (other)
		{
			if (other->n < current->n)
				i++;
			other = other->next;
		}
		current->index = i;
		current = current->next;
	}
}

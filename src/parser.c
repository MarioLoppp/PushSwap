/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:56:12 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 20:21:53 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

unsigned int	ft_stacksize(t_nums *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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

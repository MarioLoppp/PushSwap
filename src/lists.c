/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 20:04:21 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 01:16:45 by salegari         ###   ########.fr       */
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

void	moves_add_back(t_mvlst *lst, t_move *new)
{
	if (!lst || !new)
		return ;
	new->next = NULL;
	new->prev = lst->bottom;
	if (!lst->top)
		lst->top = new;
	else
		lst->bottom->next = new;
	lst->bottom = new;
	lst->size++;
}

t_move	*move_new(char *s)
{
	t_move	*new;

	new = ft_calloc(1, sizeof(t_move));
	if (!new)
		return (NULL);
	new->mv = s;
	return (new);
}

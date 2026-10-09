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

unsigned int	ft_stacksize(t_stack *lst)
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

void	lstindex(t_stack *lst)
{
	t_stack	*current;
	t_stack	*mid;
	int		i;
	int		nodes;

	i = 0;
	nodes = ft_stacksize(lst);
	while (i <= nodes)
	{
		current = lst;
		mid = NULL;
		while (current)
		{
			if (current->idx == 0 && \
				(mid == NULL || current->n < mid->n))
				mid = current;
			current = current->next;
		}
		if (mid)
			mid->n = i;
		i++;
	}
}

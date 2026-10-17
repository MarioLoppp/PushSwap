/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:50:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 01:12:35 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	valid_int(const char *str)
{
	long	value;
	long	limit;
	int		i;

	i = 0;
	value = 0;
	limit = 2147483647L;
	if (str[i] == '-')
		limit = 2147483648L;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (value > (limit - (str[i] - '0')) / 10)
			return (0);
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

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

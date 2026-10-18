/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:00:00 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/18 17:59:20 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	stack_init(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
}

int	same_op(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
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

void	free_stack(t_stack *stack)
{
	t_nums	*current;
	t_nums	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

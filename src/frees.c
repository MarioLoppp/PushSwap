/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 20:14:25 by salegari          #+#    #+#             */
/*   Updated: 2026/10/16 21:27:49 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_moves(t_mvlst *moves)
{
	t_move	*current;
	t_move	*next;

	if (!moves)
		return ;
	current = moves->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	moves->top = NULL;
	moves->bottom = NULL;
	moves->size = 0;
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

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

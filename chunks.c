/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:42:19 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/09 16:42:19 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	chunk_size(int n)
{
	int	i;

	i = 0;
	while ((long long)i * i < n)
		i++;
	return (i);
}

void	push_chunk(t_stack *a, t_stack *b, int low, int high)
{
	int	i;

	i = a->size;
	while (i > 0)
	{
		if (a->top->index >= low && a->top->index < high)
			pb(a, b);
		else
			ra(a);
		i--;
	}
}

int	max_position(t_stack *b)
{
	int		i;
	t_nums	*temp;
	int		max_index;
	int		max_position;

	if (!b->top)
		return (-1);
	temp = b->top;
	i = 0;
	max_index = temp->index;
	max_position = 0;
	while (temp)
	{
		if (temp->index > max_index)
		{
			max_index = temp->index;
			max_position = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_position);
}

/*void	sort_medium(t_stack *a, t_stack *b)
{

}*/

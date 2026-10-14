/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:25:12 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/14 17:13:42 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(t_stack *a)
{
	int	max_index;
	int	bits;

	max_index = a->size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	push_by_bit(t_stack *a, t_stack *b, int bit)
{
	if (((a->top->index >> bit) & 1) == 0)
		pb(a, b);
	else
		ra(a);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	if (!a || a->size <= 1)
		return ;
	bits = get_max_bits(a);
	i = 0;
	while (i < bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			push_by_bit(a, b, i);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

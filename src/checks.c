/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:50:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 18:50:51 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_nums *stack)
{
	while (stack && stack->next)
	{
		if (stack->idx > stack->next->idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

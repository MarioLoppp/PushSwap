/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:10:46 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 17:25:16 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	adaptive(t_stack *a, t_stack *b, t_mvlst *moves, int disorder)
{
	if (disorder < 2000)
		bubble_sort(a, b, moves);
	if (disorder >= 2000 && disorder < 5000)
		sort_medium(a, b, moves);
	if (disorder >= 5000)
		radix_sort(a, b, moves);
}

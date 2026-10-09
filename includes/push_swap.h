/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 18:05:01 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_nums
{
	int				n;
	int				idx;
	struct s_nums	*next;
}	t_nums;

typedef struct s_parse
{
	int	parse;
	int	algo;
}	t_parse;


int	sa(t_nums **a);
int	sb(t_nums **b);
int	ss(t_nums **a, t_nums **b);
int	pa(t_nums **a, t_nums **b);
int	pb(t_nums **a, t_nums **b);
int	ra(t_nums **a);
int	rb(t_nums **b);
int	rr(t_nums **a, t_nums **b);
int	rra(t_nums **a);
int	rrb(t_nums **b);
int	rrr(t_nums **a, t_nums **b);

#endif

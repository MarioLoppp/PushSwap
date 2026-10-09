/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 19:24:36 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				n;
	int				idx;
	struct s_stack	*next;
}	t_stack;

typedef struct s_parse
{
	int	parse;
	int	algo;
}	t_parse;


int	sa(t_stack **a);
int	sb(t_stack **b);
int	ss(t_stack **a, t_stack **b);
int	pa(t_stack **a, t_stack **b);
int	pb(t_stack **a, t_stack **b);
int	ra(t_stack **a);
int	rb(t_stack **b);
int	rr(t_stack **a, t_stack **b);
int	rra(t_stack **a);
int	rrb(t_stack **b);
int	rrr(t_stack **a, t_stack **b);
int	is_sorted(t_stack *stack);

#endif

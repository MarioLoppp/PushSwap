/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/14 20:46:15 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_nums
{
	int				n;
	int				index;
	struct s_nums	*prev;
	struct s_nums	*next;
}	t_nums;

typedef struct s_stack
{
	t_nums	*top;
	t_nums	*bottom;
	int		size;
	char	name;
}	t_stack;

typedef struct s_parse
{
	int	bench;
	int	algo;
}	t_parse;

int				sa(t_stack *a);
int				sb(t_stack *b);
int				ss(t_stack *a, t_stack *b);
int				pa(t_stack *a, t_stack *b);
int				pb(t_stack *a, t_stack *b);
int				ra(t_stack *a);
int				rb(t_stack *b);
int				rr(t_stack *a, t_stack *b);
int				rra(t_stack *a);
int				rrb(t_stack *b);
int				rrr(t_stack *a, t_stack *b);
int				is_sorted(t_stack *stack);
int				disorder_index(t_stack *stack);
unsigned int	ft_stacksize(t_nums *lst);
void			lstindex(t_stack *stack);
void			bubble_sort(t_stack *a, t_stack *b);
int				chunk_size(int n);
void			push_chunk(t_stack *a, t_stack *b, int low, int high);
int				max_position(t_stack *b);
void			stack_add_back(t_stack *stack, t_nums *new);
t_nums			*num_new(int n);
void			free_arr(char **arr);
int				put_in_stack(t_stack *stack, char **arr);
int				parse_ints(int ac, char **av, t_stack *stack, t_parse flags);
int				parse_flags(int ac, char **av, t_parse *flags);
void			sort_medium(t_stack *a, t_stack *b);
void			radix_sort(t_stack *a, t_stack *b);
int				repeated(t_stack *stack);
void			free_stack(t_stack *stack);
void			ft_error(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 01:33:36 by salegari         ###   ########.fr       */
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

typedef struct s_move
{
	char			*mv;
	struct s_move	*next;
	struct s_move	*prev;
}	t_move;

typedef struct s_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_count;

typedef struct s_mvlst
{
	t_move	*top;
	t_move	*bottom;
	int		size;
	t_count	count;
}	t_mvlst;

int				sa(t_stack *a, t_mvlst *moves, int flag);
int				sb(t_stack *b, t_mvlst *moves, int flag);
int				ss(t_stack *a, t_stack *b, t_mvlst *moves);
int				pa(t_stack *a, t_stack *b, t_mvlst *moves);
int				pb(t_stack *a, t_stack *b, t_mvlst *moves);
int				ra(t_stack *a, t_mvlst *moves, int flag);
int				rb(t_stack *b, t_mvlst *moves, int flag);
int				rr(t_stack *a, t_stack *b, t_mvlst *moves);
int				rra(t_stack *a, t_mvlst *moves, int flag);
int				rrb(t_stack *b, t_mvlst *moves, int flag);
int				rrr(t_stack *a, t_stack *b, t_mvlst *moves);
int				is_sorted(t_stack *stack);
int				disorder_index(t_stack *stack);
unsigned int	ft_stacksize(t_nums *lst);
void			lstindex(t_stack *stack);
void			bubble_sort(t_stack *a, t_stack *b, t_mvlst *moves);
int				chunk_size(int n);
void			push_chunk(t_stack *a, t_stack *b, int *range, t_mvlst *moves);
int				max_position(t_stack *b);
void			stack_add_back(t_stack *stack, t_nums *new);
t_nums			*num_new(int n);
void			free_arr(char **arr);
int				put_in_stack(t_stack *stack, char **arr);
int				parse_ints(int ac, char **av, t_stack *stack, t_parse flags);
int				parse_flags(int ac, char **av, t_parse *flags);
void			sort_medium(t_stack *a, t_stack *b, t_mvlst *moves);
void			radix_sort(t_stack *a, t_stack *b, t_mvlst *moves);
int				repeated(t_stack *stack);
void			free_stack(t_stack *stack);
void			free_moves(t_mvlst *moves);
void			ft_error(void);
void			print_bench(int disorder, t_parse flags, t_mvlst moves);
void			moves_add_back(t_mvlst *lst, t_move *new);
t_move			*move_new(char *s);
int				valid_int(const char *str);
unsigned int	ft_stacksize(t_nums *lst);

#endif

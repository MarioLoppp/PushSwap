/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:16:36 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/18 18:01:36 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>

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

int		read_moves(t_stack *a, t_stack *b);
int		execute_move(char *op, t_stack *a, t_stack *b);
void	stack_init(t_stack *stack, char name);
int		same_op(const char *a, const char *b);

#endif

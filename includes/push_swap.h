/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:33 by salegari          #+#    #+#             */
/*   Updated: 2026/10/11 22:01:46 by marlope3         ###   ########.fr       */
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
	t_nums 	*top;
	t_nums 	*bottom;
	int		size;
	char	name;
}	t_stack;

typedef struct s_parse
{
	int	parse;
	int	algo;
}	t_parse;

#endif

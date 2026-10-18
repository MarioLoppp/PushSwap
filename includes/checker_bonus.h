/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:16:36 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/14 20:46:39 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include <unistd.h>

int		read_moves(t_stack *a, t_stack *b);
int		execute_move(char *op, t_stack *a, t_stack *b);
void	stack_init(t_stack *stack, char name);
int		same_op(const char *a, const char *b);

#endif

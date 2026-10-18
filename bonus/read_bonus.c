/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:00:00 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/18 12:00:00 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	read_moves(t_stack *a, t_stack *b)
{
	char	op[4];
	char	c;
	int		i;
	int		status;

	i = 0;
	status = read(0, &c, 1);
	while (status > 0)
	{
		if (c == '\n')
		{
			op[i] = '\0';
			if (execute_move(op, a, b) == -1)
				return (-1);
			i = 0;
		}
		else if (i == 3 || c == '\0')
			return (-1);
		else
			op[i++] = c;
		status = read(0, &c, 1);
	}
	if (status < 0 || i != 0)
		return (-1);
	return (0);
}

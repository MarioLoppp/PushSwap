/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:25:14 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 19:26:36 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	put_in_stack(t_stack *stack, char **arr)
{
	t_nums	*new;
	int		i;

	i = 0;
	while (arr[i])
	{
		if (!valid_int(arr[i]))
			return (-1);
		new = num_new(ft_atoi(arr[i]));
		if (!new)
			return (-1);
		stack_add_back(stack, new);
		i++;
	}
	return (1);
}

int	parse_ints(int ac, char **av, t_stack *stack)
{
	int		i;
	char	**arr;
	int		result;

	i = 1;
	while (i < ac && ft_strncmp(av[i], "--", 2) == 0)
		i++;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			return (-1);
		if (!arr[0])
			return (free_arr(arr), -1);
		result = put_in_stack(stack, arr);
		free_arr(arr);
		if (result == -1)
			return (-1);
		i++;
	}
	if (repeated(stack) == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:56:12 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 01:16:24 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstindex(t_stack *stack)
{
	t_nums	*current;
	t_nums	*other;
	int		i;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		i = 0;
		other = stack->top;
		while (other)
		{
			if (other->n < current->n)
				i++;
			other = other->next;
		}
		current->index = i;
		current = current->next;
	}
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

int	parse_ints(int ac, char **av, t_stack *stack, t_parse flags)
{
	int		i;
	char	**arr;
	int		result;

	i = 1;
	if (flags.algo > 0)
		i++;
	if (flags.bench > 0)
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

static int	get_flag(char *arg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (3);
	// if (ft_strncmp(arg, "--adaptive", 11) == 0)
	// 	return (4);
	return (-1);
}

int	parse_flags(int ac, char **av, t_parse *flags)
{
	int	i;
	int	value;

	flags->algo = -1;
	flags->bench = 0;
	i = 1;
	while (i < ac && ft_strncmp(av[i], "--", 2) == 0)
	{
		value = get_flag(av[i]);
		if (value == -1 || (value == 0 && flags->bench)
			|| (value > 0 && flags->algo != -1))
			return (-1);
		if (value == 0)
			flags->bench = 1;
		else
			flags->algo = value;
		i++;
	}
	// if (flags->algo == -1)
	// 	flags->algo = 4;
	return (1);
}

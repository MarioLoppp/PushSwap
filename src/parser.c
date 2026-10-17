/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:56:12 by salegari          #+#    #+#             */
/*   Updated: 2026/10/18 00:55:17 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	valid_int(const char *str)
{
	long	value;
	long	limit;
	int		i;

	i = 0;
	value = 0;
	limit = 2147483647L;
	if (str[i] == '-')
		limit = 2147483648L;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (value > (limit - (str[i] - '0')) / 10)
			return (0);
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

unsigned int	ft_stacksize(t_nums *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

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

int	parse_flags(int ac, char **av, t_parse *flags)
{
	int	algo;
	int	bench;

	algo = -1;
	bench = 0;
	if (ac > 2)
	{
		if (ft_strnstr(av[1], "--bench", 7)
			|| ft_strnstr(av[2], "--bench", 7))
			bench = 1;
		if (ft_strnstr(av[1], "--simple", 8)
			|| ft_strnstr(av[2], "--simple", 8))
			algo = 1;
		if (ft_strnstr(av[1], "--medium", 8)
			|| ft_strnstr(av[2], "--medium", 8))
			algo = 2;
		if (ft_strnstr(av[1], "--complex", 9)
			|| ft_strnstr(av[2], "--complex", 9))
			algo = 3;
	}
	flags->algo = algo;
	flags->bench = bench;
	return (1);
}

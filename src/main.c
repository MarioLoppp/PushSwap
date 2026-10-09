/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:46:09 by salegari          #+#    #+#             */
/*   Updated: 2026/10/09 18:03:40 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parse_input(int ac, char **av, t_nums nums)
{
	exit(1);
}

int	main(int ac, char **av)
{
	t_nums	nums;

	if (ac < 2)
	{
		ft_printf("Error\n");
		exit(2);
	}
	parse_input(ac, av, nums);
}

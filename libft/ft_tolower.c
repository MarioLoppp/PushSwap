/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:15:08 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 18:51:07 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c +32);
	return (c);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char c = 'A';
// 	printf("Original: %c\n", c);
// 	printf("Lowered: %c\n", ft_tolower(c));
// 	return 0;
// }

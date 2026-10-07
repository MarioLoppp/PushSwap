/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:12:51 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 18:51:01 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -32);
	return (c);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char c = 'a';
// 	printf("Original: %c\n", c);
// 	printf("Uppped: %c\n", ft_toupper(c));
// 	return 0;
// }

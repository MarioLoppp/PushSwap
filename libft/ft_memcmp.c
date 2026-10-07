/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:06:51 by salegari          #+#    #+#             */
/*   Updated: 2026/09/21 20:10:26 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	s1[] = "Hola";
// 	char	s2[] = "Holb";
//
// 	printf("%d\n", ft_memcmp(s1, s2, 4));
// 	printf("%d\n", ft_memcmp(s1, s2, 3));
// 	return (0);
// }

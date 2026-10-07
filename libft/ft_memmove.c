/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:53:01 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 19:07:48 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (src < dest)
	{
		while (n--)
			d[n] = s[n];
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	unsigned char s[] = "Hola que tal";
// 	unsigned char d[13];
//
// 	ft_memmove(d, s, 12);
// 	printf("src: %s\ndst: %s\n", s, d);
// 	return 0;
// }

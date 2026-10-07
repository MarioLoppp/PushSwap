/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:57:09 by salegari          #+#    #+#             */
/*   Updated: 2026/09/21 20:05:45 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	s[] = "Hola";
// 	char	*res;
//
// 	res = ft_memchr(s, 'l', 5);
// 	printf("%s\n", res);
// 	return (0);
// }

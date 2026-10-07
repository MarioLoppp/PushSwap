/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:06:40 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 19:26:17 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	src[] = "Hola que tal";
// 	char	dest[50];
//
// 	printf("Longitud src: %u\n", ft_strlcpy(dest, src, 6));
// 	printf("src:  %s\n", src);
// 	printf("dest: %s\n", dest);
//
// 	return (0);
// }

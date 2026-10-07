/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:30:16 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 19:21:54 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen((char *)src) + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*original;
// 	char	*copia;
//
// 	original = "Hola que tal";
// 	copia = ft_strdup(original);
//
// 	printf("Original: %s\n", original);
// 	printf("Copia: %s\n", copia);
//
// 	free(copia);
// 	return (0);
// }

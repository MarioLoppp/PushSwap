/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:09:06 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 19:24:52 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	j;

	d_len = 0;
	s_len = ft_strlen(src);
	while (d_len < size && dest[d_len])
		d_len++;
	if (d_len == size)
		return (size + s_len);
	j = 0;
	while (src[j] && d_len + j + 1 < size)
	{
		dest[d_len + j] = src[j];
		j++;
	}
	dest[d_len + j] = '\0';
	return (d_len + s_len);
}

// #include <stdio.h>
//
// int main(void)
// {
// 	char destino[50] = "Hola,";
// 	char origen[] = "Mundo!";
//
// 	ft_strlcat(destino, origen, 9);
// 	printf("Resultado: %s\n", destino);
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:22:37 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 20:39:34 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s + start, len + 1);
	return (res);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char const	*str = "¡Hola, mundo de 42!";
// 	char		*sub;
//
// 	sub = ft_substr(str, 7, 5);
// 	printf("Cadena original: %s\n", str);
// 	printf("Subcadena obtenida: %s\n", sub ? sub : "(null)");
// 	if (sub)
// 		free(sub);
// 	return (0);
// }

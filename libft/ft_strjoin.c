/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:40:41 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 20:52:35 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1, ft_strlen(s1) +1);
	ft_strlcat(res, (char *)s2, ft_strlen(s1) + ft_strlen(s2) +1);
	return (res);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char const	*s1 = "Hola, ";
// 	char const	*s2 = "mundo";
// 	char		*result;
//
// 	result = ft_strjoin(s1, s2);
// 	printf("S1: %s\n", s1);
// 	printf("S2: %s\n", s2);
// 	printf("Resultado join: %s\n", result ? result : "(null)");
// 	if (result)
// 		free(result);
// 	return (0);
// }

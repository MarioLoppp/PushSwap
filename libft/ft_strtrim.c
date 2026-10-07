/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:55:21 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 20:58:36 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (!set)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	while (s1[end] && ft_strchr(set, s1[end]))
		--end;
	dst = ft_substr(s1, start, end - start + 1);
	return (dst);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char const	*s1 = "   xxHola Mundo de 42xx   ";
// 	char const	*set = " x";
// 	char		*trimmed;
//
// 	trimmed = ft_strtrim(s1, set);
// 	printf("Original: '%s'\n", s1);
// 	printf("Set: '%s'\n", set);
// 	printf("Resultado trim: '%s'\n", trimmed ? trimmed : "(null)");
// 	if (trimmed)
// 		free(trimmed);
// 	return (0);
// }

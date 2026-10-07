/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 21:23:02 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 21:28:12 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s1;

	if (!s)
		return (NULL);
	i = 0;
	s1 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s1 || !f)
		return (NULL);
	if (!s1)
		return (NULL);
	while (i < ft_strlen(s))
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// #include <stdio.h>
//
// static char	shift_char(unsigned int i, char c)
// {
// 	(void)i;
// 	return (c + 1);
// }
//
// int	main(void)
// {
// 	char const	*str = "hola mundo de 42";
// 	char		*result;
//
// 	result = ft_strmapi(str, shift_char);
// 	printf("Cadena original: %s\n", str);
// 	printf("Resultado mapi : %s\n", result ? result : "(null)");
// 	if (result)
// 		free(result);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:17:03 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 19:37:50 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			last = (char *)s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		last = (char *)s;
	return (last);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char *s = "testee";
// 	int c = 't';
//
// 	printf("%s\n", ft_strrchr(s, c));
// 	printf("%s\n", strrchr(s, c));
// 	return 0;
// }

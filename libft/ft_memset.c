/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:16:07 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 18:39:11 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char s[15];
//
// 	ft_memset(s, 'o', 15);
// 	printf("res: %s\n", s);
// 	return 0;
// }

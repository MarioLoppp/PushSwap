/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:16:07 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 18:54:57 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char s[15];
// 	int i = 0;
//
// 	ft_memset(s, 'a', 15);
// 	ft_bzero(s, 15);
// 	printf("res: ");
// 	while (i <= 15)
// 	{
// 		printf("%c", s[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return 0;
// }

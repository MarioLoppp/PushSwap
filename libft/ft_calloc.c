/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:35:18 by salegari          #+#    #+#             */
/*   Updated: 2026/09/23 20:58:50 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > (size_t)(-1) / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	int	*tab;
// 	int	i;
//
// 	tab = ft_calloc(5, sizeof(int));
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	system("leaks a.out");
// 	return (0);
// }

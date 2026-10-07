/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 21:52:56 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 21:57:54 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
//
// void	my_toupper_if_even(unsigned int index, char *c)
// {
// 	if (index % 2 == 0 && *c >= 'a' && *c <= 'z')
// 		*c -= 32;
// }
//
// int	main(void)
// {
// 	char	str[] = "hola mundo 42";
//
// 	printf("Cadena antes de ft_striteri: %s\n", str);
// 	ft_striteri(str, my_toupper_if_even);
// 	printf("Cadena despues de ft_striteri: %s\n", str);
// 	return (0);
// }

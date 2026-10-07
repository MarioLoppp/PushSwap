/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 21:16:32 by salegari          #+#    #+#             */
/*   Updated: 2026/09/22 21:19:12 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n, int sign)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (sign == -1)
		++len;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	len = ft_intlen(n, sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return 0;
// }

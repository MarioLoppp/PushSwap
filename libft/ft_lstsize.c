/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:08:04 by salegari          #+#    #+#             */
/*   Updated: 2026/09/23 19:19:15 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// #include <stdio.h>
//
// int	main(void)
// {
//     t_list	*head;
//     t_list	*node2;
//     t_list	*node3;
//
//     head = ft_lstnew("1");
//     node2 = ft_lstnew("2");
//     node3 = ft_lstnew("3");
//
//     head->next = node2;
//     node2->next = node3;
//
//     printf("Size: %u\n", ft_lstsize(head));
//     printf("Empty: %u\n", ft_lstsize(NULL));
//
//     free(head);
//     free(node2);
//     free(node3);
//
//     return (0);
// }

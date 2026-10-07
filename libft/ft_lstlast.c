/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:16:30 by salegari          #+#    #+#             */
/*   Updated: 2026/09/23 21:03:25 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
//
// int	main(void)
// {
//     t_list	*head;
//     t_list	*node2;
//     t_list	*node3;
// 	t_list	*last;
//
//     head = ft_lstnew("1");
//     node2 = ft_lstnew("2");
//     node3 = ft_lstnew("3");
//
//     head->next = node2;
//     node2->next = node3;
//
// 	last = ft_lstlast(head);
//
//     printf("Last: %s\n", (char *)last->content);
//
//     free(head);
//     free(node2);
//     free(node3);
//
//     return (0);
// }

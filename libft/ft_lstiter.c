/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 21:35:48 by salegari          #+#    #+#             */
/*   Updated: 2026/09/23 21:38:29 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
//
// void	print_str(void *content)
// {
//     printf("%s\n", (char *)content);
// }
//
// int	main(void)
// {
// 	t_list	*n1 = malloc(sizeof(t_list));
// 	t_list	*n2 = malloc(sizeof(t_list));
//
// 	n1->content = "Hola";
// 	n1->next = n2;
// 	n2->content = "mundo";
// 	n2->next = NULL;
//
// 	ft_lstiter(n1, print_str);
// 	free(n1);
// 	free(n2);
// 	return (0);
// }

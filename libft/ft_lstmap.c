/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 21:39:35 by salegari          #+#    #+#             */
/*   Updated: 2026/09/23 22:10:28 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;
	t_list	*new;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	start = ft_lstnew(content);
	if (!start)
		return (del(content), NULL);
	tmp = start;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
			return (del(content), ft_lstclear(&start, del), NULL);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (start);
}

// #include <stdio.h>
//
// void	*f_dup(void *content)
// {
//     return (ft_strdup((char *)content));
// }
//
// void	del_content(void *content)
// {
//     free(content);
// }
//
// int	main(void)
// {
//     t_list	*n1 = ft_lstnew(ft_strdup("hola"));
//     t_list	*n2 = ft_lstnew(ft_strdup("mundo"));
//
//     n1->next = n2;
//     t_list	*single_node = ft_lstnew(ft_strdup("prueba_delone"));
//     ft_lstdelone(single_node, del_content);
//     t_list	*new_list = ft_lstmap(n1, f_dup, del_content);
//     printf("%s\n", (char *)new_list->content);
//     printf("%s\n", (char *)new_list->next->content);
//     ft_lstclear(&n1, del_content);
//     ft_lstclear(&new_list, del_content);
//     return (0);
// }

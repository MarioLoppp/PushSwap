/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:02:06 by salegari          #+#    #+#             */
/*   Updated: 2026/09/23 19:51:03 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
//
// int main(void)
// {
//     t_list *head = NULL;
//     t_list *n1 = malloc(sizeof(t_list));
//
//     n1->content = "Mundo";
//     n1->next = NULL;
//
//     head = n1;
//     t_list *n2 = malloc(sizeof(t_list));
//     n2->content = "Hola";
//     n2->next = NULL;
//     ft_lstadd_front(&head, n2);
//     printf("1: %s\n2: %s\n", (char *)head->content, 
//     (char *)head->next->content);
//     free(n1);
//     free(n2);
//     return (0);
// }

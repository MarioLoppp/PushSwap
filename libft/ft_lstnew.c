/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegari <salegari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:58:44 by salegari          #+#    #+#             */
/*   Updated: 2026/09/23 19:51:59 by salegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(1 * sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// #include <stdio.h>
//
// int main(void)
// {
//     t_list *elem;
//     char   *texto = "Hello World";
//
//     elem = ft_lstnew(texto);
//     if (elem == NULL)
//     {
//         printf("Error: Falló la asignación de memoria.\n");
//         return (1);
//     }
//     printf("Contenido del nodo: %s\n", (char *)elem->content);
//     if (elem->next == NULL)
//         printf("El puntero 'next' apunta a NULL correctamente.\n");
//     free(elem);
//
//     return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:49:09 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:59 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Creates a new node for a linked
 list with the specified content.
 *
 * \param content Pointer to the content to
 be stored in the new node.

 * \return Pointer to the newly created node
 (t_list). NULL if memory allocation fails
 *

 * \remark function allocates memory for a
 new node in a linked list (t_list) and
 initializes its content

 * and next pointer. The content of the new
 node is set to the value of the \p content parameter,
	and

 * the next pointer is set to NULL. If memory
 allocation fails during the creation of the new node,
 * the function returns NULL to indicate an error.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

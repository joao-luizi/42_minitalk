/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:25:26 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:57 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**

 * @brief Iterates over a linked list and applies a
 function to each element's content.
 *
 * This function iterates over the linked list 'lst'
 and applies the function 'f' to the content of each node.
 * It creates a new linked list resulting from the
 successive applications of the function 'f'.
 * The 'del' function is used to delete the content of
 a node if needed.
 *
 * @param lst A pointer to the first element of the
 linked list.
 * @param f A pointer to the function to apply to each
 element's content.
 * @param del A pointer to the function used to delete the
 content of a node if needed.
 *
 * @return A pointer to the first element of the new
 linked list,
	or NULL if an error occurred.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

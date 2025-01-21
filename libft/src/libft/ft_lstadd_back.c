/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:51:44 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:42 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Adds a new node to the
 end of a linked list.
 *
 * \param lst Pointer to the pointer
 to the head of the linked list.
 * \param new Pointer to the new node
 to be added to the end of the list.
 * \return None
 *
 * \remark function adds a new node
 (\p new) to the end of a linked list
 whose head pointer is passed by reference

 * (\p lst). If either the pointer to
 the head of the list (\p lst) or the
 pointer to the new node (\p new) is
 * NULL,
	the function returns without performing
	any operation. If the linked list is empty (i.e.,
	the head pointer
 * is NULL), the function sets the head pointer
 to point to the new node,
	effectively making it the first node in
 * the list. Otherwise,
	it traverses the list to find the last node
	(the node with a NULL `next` pointer) and appends

	* the new node to its `next` pointer. This
	function efficiently adds a node to the end
	of a linked list and updates
 * the necessary pointers to maintain the integrity
 of the list structure.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

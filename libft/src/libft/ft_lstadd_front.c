/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:50:21 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:44 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Adds a new node to the front
 of a linked list.
 *
 * \param lst Pointer to the pointer to
 the head of the linked list.
 * \param new Pointer to the new node to
 be added to the front of the list.
 * \return None
 *

 * \remark function adds a new node (\p new)
 to the front of a linked list whose head
 pointer is passed by reference
 * (\p lst). The new node becomes the new
 head of the list,
	and its next pointer is set to point to
	the previous
 * head of the list. If either the pointer to
 the head of the list (\p lst) or the pointer
 to the new node (\p new)
 * is NULL,
	the function returns without performing any
	operation. This function efficiently prepends
	a node to the

	* front of a linked list and updates the
	necessary pointers to maintain the integrity of the list structure.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

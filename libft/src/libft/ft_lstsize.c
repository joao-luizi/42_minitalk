/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:47:37 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:01 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Determines the size of a
 linked list.
 *
 * \param lst Pointer to the head of
 the linked list.
 * \return The number of nodes in the
 linked list.
 *
 * This function calculates the size of a
 linked list by traversing through each node
 starting from the

 * head of the list (\p lst). It initializes
 a counter variable (\p len) to 0 and increments
 it for each

 * node encountered while traversing the list.
 If the head pointer (\p lst) is NULL,
	indicating an empty
 * list, the function returns 0. Otherwise,
	it iterates through the list until it reaches
	the end (i.e.,
 * the last node where the `next` pointer is NULL),
	counting each node along the way. Finally, it
	returns
 * the total count of nodes in the linked list.
 */
int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

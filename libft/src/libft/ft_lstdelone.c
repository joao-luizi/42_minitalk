/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:46:22 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:49 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Deletes a single node from a linked list.
 *
 * This function deletes the content of the given
 node using the provided `del` function pointer,
	then frees the memory allocated for the node itself.
 *
 * @param lst A pointer to the node to be deleted.
 * @param del A pointer to the function used to delete
 the content of the node.
 *            The function must conform to the
 following prototype:
 *            `void del(void *)`.
 *
 * @remarks If `lst` is NULL, no action is taken.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

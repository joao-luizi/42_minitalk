/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:29:09 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:51 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**

 * @brief Iterates over a linked list and applies
 a given function to each node's content.
 *
 * This function traverses the linked list pointed
 to by `lst` and applies the function pointed to
 by `f` to the content of each node.
 *
 * @param lst A pointer to the first node of the
 linked list.
 * @param f A pointer to the function to be applied
 to the content of each node.
 *          The function must conform to the
 following prototype:
 * `void f(void *)`.
 *
 * @remarks If `lst` is NULL or `f` is NULL,
 no action is taken.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

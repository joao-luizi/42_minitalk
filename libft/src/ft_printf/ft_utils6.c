/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:21:34 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:21:34 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Prints the content of a linked 
 * list of printable nodes to the standard output.
 *
 * This function iterates through the linked
 *  list @p lst, printing the content of each node
 * to the standard output using the `write` 
 * system call. It also checks for nodes with errors
 * indicated by a specifier value of -1 and 
 * stops printing if such a node is encountered.
 *
 * @param lst A pointer to the head of the 
 * linked list of printable nodes.
 * @return The total number of characters 
 * printed if successful, or -1 if an error occurs.
 */
int	ft_lstprint(t_info_list *lst)
{
	size_t	count;
	size_t	count_write;

	count = 0;
	count_write = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		if (lst->info == NULL || lst->info->specifier == -1)
		{
			count = -1;
			break ;
		}
		else
		{
			count_write += write(1, (char *)lst->content, lst->info->str_len);
			count += lst->info->str_len;
		}
		lst = lst->next;
	}
	return (count);
}

/**
 * @brief Frees the memory associated with
 *  a linked list.
 *
 * This auxiliary function frees all the 
 * nodes in the linked list, including the 
 * memory allocated for the content and info
 *  fields. After freeing all nodes, it 
 * sets the list pointer to NULL.
 *
 * @param lst A double pointer to the head 
 * of the linked list to be freed.
 */
void	free_list(t_info_list **lst)
{
	t_info_list	*temp;
	t_info_list	*head;

	if (!lst)
		return ;
	head = *lst;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp->info);
		free(temp);
	}
	*lst = NULL;
}

/**
 * @brief Appends a new node to the end of a 
 * linked list.
 *
 * This auxiliary function appends a new node 
 * to the end of the provided linked list.
 * If the list is empty, the new node becomes 
 * the first node.
 *
 * @param lst A double pointer to the head of 
 * the linked list.
 * @param new The new node to be appended to 
 * the list.
 */
void	ft_info_lst_add_back(t_info_list **lst, t_info_list *new)
{
	t_info_list	*temp;

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

/**
 * @brief Counts characters in a string that
 *  are not in the specified list.
 *
 * This auxiliary function counts the number
 *  of characters in the given string
 * that do not belong to the provided list of
 *  characters. It is used for template
 * validation purposes.
 *
 * @param str The string to be evaluated.
 * @param lst The list of characters to exclude
 *  from the count.
 *
 * @return The count of characters in the string
 *  that are not in the list.
 */
size_t	ft_strlenif(char *str, char *lst)
{
	size_t	result;

	result = 0;
	while (*str)
	{
		if (!ft_ischarinlist(lst,*str))
			result++;
		str++;
	}
	return (result);
}

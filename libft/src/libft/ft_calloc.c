/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:11:24 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:25 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**

* @brief Allocates memory for an array of
nmemb elements of size bytes each and initializes
the allocated memory to zero.
 *
 * This function allocates a block of memory
 for an array of `nmemb` elements,
	each of which has a size of `size` bytes.
 * The total amount of memory allocated is equal
 to `nmemb
	* size` bytes. If either `nmemb` or `size` is
	zero, this
	* function returns NULL without allocating any
	memory. The allocated memory is then initialized to zero.
	Calls `libft.a` funtion `ft_bzero()`.
 *
 * @param nmemb The number of elements to allocate
 memory for.
 * @param size The size of each element in bytes.
 * @return Upon successful completion,
	`ft_calloc` returns a pointer to the allocated
	memory. If the allocation fails,
 *         the function returns NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (nmemb && size && nmemb != (nmemb * size) / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

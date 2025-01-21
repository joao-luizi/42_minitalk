/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:27 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:12 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Copies a block of memory,
 * handling overlapping regions.
 *
 * This function copies `n` bytes of
 * memory from the source address `src` to the
 * destination address `dest`. The copying
 * is performed in a way that it safely handles
 * cases where the source and destination
 * memory regions overlap.
 *
 * @param dest Pointer to the destination
 * memory where the data will be copied.
 * @param src Pointer to the source memory
 * from which the data will be copied.
 * @param n Number of bytes to copy.
 *
 * @return Pointer to the destination
 * memory (`dest`).
 *
 * @note If both `dest` and `src` pointers
 * are `NULL`, the function returns `dest`.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

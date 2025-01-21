/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:42:54 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:10 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**

 * @brief Copies a block of memory from
 a source location to a destination location.
 *
 * This function copies 'n' bytes of memory
 from the source memory location 'src'
 * to the destination memory location 'dest'.
 The memory areas must not overlap.
 *

 * @param dest Pointer to the destination memory
 location where the content is to be copied.
 * @param src Pointer to the source memory location
 to copy from.
 * @param n Number of bytes to copy.
 * @return A pointer to the destination memory
 location 'dest'.
 *
 * @remark Both 'dest' and 'src' must point to
 valid memory locations,
	or the behavior is undefined.
	* @remark The memory areas pointed to by 'dest'
	and 'src' must not overlap. Use memmove() if
	overlap is possible.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	pdest = (char *)dest;
	psrc = (const char *)src;
	if (pdest != NULL && psrc != NULL)
	{
		while (n > 0)
		{
			*pdest = *psrc;
			psrc++;
			pdest++;
			n--;
		}
	}
	return (dest);
}

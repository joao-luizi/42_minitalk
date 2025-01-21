/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:36:09 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:15 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Fills a block of memory
 with a specified value.
 *
 * This function fills the first
 'n' bytes of the memory area pointed
 to by 'dest'
	* with the specified value 'c'.
	It returns a pointer to the destination
	memory area.
 *
 * @param dest Pointer to the memory area
 to be filled.
 * @param c Value to be set. The value is
 passed as an int,
	but it is converted to
 *          an unsigned char for filling
 the memory area.
 * @param n Number of bytes to be filled
 with the value 'c'.
 * @return A pointer to the destination
 memory area 'dest'.
 *
 */
void	*ft_memset(void *dest, int c, size_t n)
{
	char	*pdest;

	pdest = dest;
	while (n > 0)
	{
		*pdest = (unsigned char)c;
		pdest++;
		n--;
	}
	return (dest);
}

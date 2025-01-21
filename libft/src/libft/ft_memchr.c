/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:45:59 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:04 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Locate the first occurrence of
 a character in a memory block.
 *
 * This function searches within the first
 'n' bytes of the memory block pointed to by
 's' for the first occurrence
 * of the character 'c' (both converted to
 an unsigned char).
 *
 * @param s Pointer to the memory block to
 be searched.
 * @param c The character to search for.
 * @param n Number of bytes to search within
 the memory block.
 * @return A pointer to the first occurrence
 of 'c' within the first 'n' bytes of the
 memory block 's',
 *         or a null pointer if 'c' is not
 found within the specified range.
 *
 * @remark The function iterates through the
 memory block pointed to by 's' until it finds the
 character 'c'
 *         or until 'n' bytes have been searched,
	whichever comes first. If 'c' is found
	within the specified
 *         range,
	the function returns a pointer to its
	location within the memory block. If 'c'
	is not found
 *         within the specified range, the
 function returns a null pointer.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}

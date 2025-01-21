/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:26 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:08 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Compare the first 'n' bytes
 of two memory blocks.
 *
 * This function compares the first 'n'
 bytes of the memory blocks pointed to by
 's1' and 's2'.
 *
 * @param s1 Pointer to the first memory
 block to be compared.
 * @param s2 Pointer to the second memory
 block to be compared.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to,
	or greater than zero if the first 'n'
	bytes of 's1' are found,
 *         respectively, to be less than,
 to match,
	or be greater than the first 'n' bytes
	of 's2'.
 *
 * @remark The function compares bytes from
 both memory blocks until 'n' bytes have been compared,
 *         or until a null terminator ('\0')
 is encountered in either block,
	whichever comes first.
 *         If the contents of both memory blocks
 are equal up to the first 'n' bytes,
	the function returns 0.
 *         Otherwise,
	it returns the difference between the values of
	the first differing bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*one;
	char	*two;

	i = 0;
	one = (char *)s1;
	two = (char *)s2;
	while (i < n)
	{
		if (one[i] != two[i])
			return ((unsigned char)one[i] - (unsigned char)two[i]);
		i++;
	}
	return (0);
}

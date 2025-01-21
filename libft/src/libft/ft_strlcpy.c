/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:42:00 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:06 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Copies a string into a fixed-size
 buffer, ensuring null-termination.
 *
 * This function copies the string pointed
 to by 'src' (including the null terminator)
 * into the buffer pointed to by 'dst'. At
 most, 'dstsize
	- 1' characters are copied from
 * 'src' to 'dst',
	and the destination string is always
	null-terminated. The total length
 * of the source string is returned. If
 'dstsize' is zero,
	the function returns the length
 * of the source string without copying anything.
 Calls `libft.a` function `ft_strlen()`.
 *
 * @param dst Pointer to the destination buffer
 where the string is copied.
 * @param src Pointer to the source string to
 be copied.
 * @param dstsize Size of the destination buffer.
 * @return The length of the source string
 (excluding the null terminator).
 *
 * @remark The function ensures that the destination
 buffer is null-terminated,
 *         even if 'dstsize' is insufficient to hold
 the entire source string.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	while (dstsize > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (src_length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:43:16 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:03 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**

	* @brief Concatenates two strings ensuring
	null-termination and limited buffer overflow.
 *
 * This function concatenates the string 'src'
 * to the end of the string 'dst' ensuring that
 * the resulting string is null-terminated and
 * fits within the buffer of size 'dstsize'.
 * If 'dstsize' is less than or equal to the
 * length of 'dst', the function returns the sum
 * of 'dstsize' and the length of 'src'.
 * Otherwise, it appends characters from 'src' to 'dst'
 * until 'dstsize' is reached or 'src' is fully copied.

	*  The resulting string is null-terminated. Calls
	`libft.a` function `ft_strlen()`
 *
 * @param dst A pointer to the destination string where
 * 'src' will be concatenated.
 * @param src The source string to be appended to 'dst'.
 * @param dstsize The size of the destination buffer
 * including null-termination.
 * @return The total length of the concatenated string
 *  if the operation is successful and
 *         the concatenated string is null-terminated.
 *  If the buffer size is insufficient
 *         to hold the concatenated string, the function
 *  returns the sum of 'dstsize' and
 *         the length of 'src' without any concatenation.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	j = 0;
	while (src[j] && dstsize > i + 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:33:48 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:30 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Locates the first occurrence of a
 character in a string.
 *
 * This function searches for the first occurrence
 of the character 'c' (converted to an unsigned char)
 * in the string pointed to by 's'. The search
 includes the null terminator '\0'.
 *
 * @param s Pointer to the null-terminated string
 to be searched.
 * @param c The character to search for.
 * @return A pointer to the located character in the
 string 's',
	or a null pointer if the character 'c'
 *         is not found in the string.
 *
 * @remark The function returns a pointer to the first
 occurrence of 'c' in 's',
	or a null pointer
 *         if 'c' is not found. If 'c' is the null
 terminator ('\0'),
	the function returns a pointer
 *         to the null terminator at the end of 's'.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

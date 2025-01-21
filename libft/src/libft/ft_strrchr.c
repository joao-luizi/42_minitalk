/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:35:22 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:21 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Locates the last occurrence
 of a character in a string.
 *
 * This function searches for the last
 occurrence of the character 'c'
 * in the string pointed to by 's'. The
 search includes the null terminator '\0'.
 Calls `libft.a` function `ft_strlen()`.
 *
 * @param s Pointer to the null-terminated
 string to be searched.
 * @param c The character to search for.
 * @return A pointer to the located character
 in the string 's',
	or a null pointer if the character 'c'
 *         is not found in the string.
 *
 * @remark The function returns a pointer to
 the last occurrence of 'c' in 's',
	or a null pointer
 *         if 'c' is not found. If 'c' is the
 null terminator ('\0'),
	the function returns a pointer
 *         to the null terminator at the end of 's'.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:36:41 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:15 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Compare characters of two strings
 up to a specified length.
 *
 * This function compares the first 'n'
 characters of the null-terminated strings 's1' and 's2'.
 *
 * @param s1 Pointer to the first null-terminated
 string to be compared.
 * @param s2 Pointer to the second null-terminated
 string to be compared.
 * @param n Number of characters to compare.
 * @return An integer less than, equal to,
	or greater than zero if the first 'n' characters
	of 's1' are found,
 *         respectively, to be less than, to match,
	or be greater than the first 'n' characters of 's2'.
 *

 * @remark The function compares characters from
 both strings until 'n' characters have been compared,
 *         or until a null terminator ('\0') is
 encountered in either string,
	whichever comes first.

 *         If the contents of both strings are equal
 up to the first 'n' characters,
	or if both strings

 *  reach a null terminator at the same position
 within the first 'n' characters,
	the function returns 0.
 *         Otherwise,
	it returns the difference between the
	ASCII values of the first differing characters.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

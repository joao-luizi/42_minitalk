/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:19 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:18 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Locates the first occurrence of a
 * substring within a limited length string.
 *
 * This function searches for the first occurrence
 *  of the substring 'little' within the string 'big',
 * up to a maximum length of 'len'. If 'little'
 * is an empty string, a pointer to 'big' is returned.
 * The search terminates if the end of 'big' is reached
 *  or if 'len' characters have been searched.
 *
 * @param big The string to be searched within.
 * @param little The substring to search for.
 * @param len The maximum number of characters
 * to search within 'big'.
 * @return A pointer to the first occurrence of 'little'
 * within 'big' if found within the specified
 *         length, or NULL if 'little' is not found or
 * if 'len' is less than the length of 'big'.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	strinpos;
	size_t	i;

	strinpos = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[strinpos] != '\0' && strinpos < len)
	{
		i = 0;
		while (little[i] != '\0' && little[i] == big[strinpos + i]
			&& big[strinpos + i] != '\0' && strinpos + i < len)
		{
			i++;
		}
		if (little[i] == '\0')
			return ((char *)big + strinpos);
		strinpos++;
	}
	return (NULL);
}

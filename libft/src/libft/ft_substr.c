/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:25:40 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:27 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Allocates and returns a substring
 from the input string.
 *
 * This function allocates memory for a substring
 from the input string 's'.
 * The substring begins at the specified index
 'start' and has a maximum length
 * of 'len' characters. The allocated memory
 is dynamically allocated using malloc.
 Calls `libft.a` functions `ft_strlen()`, `ft_strdup()`
 *
 * @param s The input string from which to
 create the substring.
 * @param start The start index of the substring
 in the input string 's'.
 * @param len The maximum length of the substring.
 * @return The substring if successful,
	or NULL if the allocation fails or 's' is NULL.
 *
 * @warning The caller is responsible for freeing
 the memory allocated by this function
 * using free() when it is no longer needed to
 prevent memory leaks.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (start + len > size)
		len = size - start;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

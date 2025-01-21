/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:44:46 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:00 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Concatenates two strings and
 returns the result.
 *
 * This function allocates memory for a
 new string that is the concatenation
 * of the prefix string 's1' and the suffix
 string 's2'. The memory for the
 * concatenated string is dynamically
 allocated using malloc. Calls `libft.a` function `ft_strlen()`
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The concatenated string if successful,
	or NULL if the allocation fails
 *         or either 's1' or 's2' is NULL.
 *
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*p_copy;

	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	p_copy = p;
	while (*s1 != '\0')
	{
		*p = *s1;
		s1++;
		p++;
	}
	while (*s2 != '\0')
	{
		*p = *s2;
		s2++;
		p++;
	}
	*p = '\0';
	return (p_copy);
}

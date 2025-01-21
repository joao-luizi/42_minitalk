/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:26:54 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:25 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Trims characters specified in the set
 from the beginning and end of a string.
 *
 * This function allocates memory for a new string
 that is a trimmed version of the input string 's1'.
 * Characters specified in the reference set 'set'
 are removed from the beginning and end of 's1'.
 * The memory for the trimmed string is dynamically
 allocated using malloc.
 Calls `libft.a` function `ft_substr` an `ft_strchr`.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string if successful, or NULL
 if the allocation fails.
 *
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;

	end = ft_strlen(s1) - 1;
	start = 0;
	if (!s1)
		return (NULL);
	if (*set == '\0')
		return (ft_strdup(s1));
	while (s1[start] && (ft_strchr(set, s1[start])))
		start++;
	while (s1[end] && (ft_strchr(set, s1[end])))
		end--;
	p = ft_substr(s1, start, end - start + 1);
	return (p);
}

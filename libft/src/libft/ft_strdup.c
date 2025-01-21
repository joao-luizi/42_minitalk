/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:10 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:33 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Duplicates a string.
 *
 * Allocates memory for a new string containing
 a copy of the input string `s`,
 * including the null terminator. The function
	returns a pointer to the newly allocated
 * string. Calls `libft.a` function `ft_strlen()`
 *
 * @param s The string to be duplicated.
 * @return A pointer to the newly allocated string,
	or NULL if memory allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*p;
	char	*p_copy;
	size_t	s_len;

	s_len = ft_strlen(s);
	p = malloc(s_len + 1);
	if (p == NULL)
		return (NULL);
	p_copy = p;
	while (*s != '\0')
	{
		*p = *s;
		p++;
		s++;
	}
	*p = '\0';
	return (p_copy);
}

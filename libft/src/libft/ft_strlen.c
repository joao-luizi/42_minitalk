/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:40:43 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:08 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calculates the length of a null-terminated
 string.
 *
 * This function calculates the length of the
 null-terminated string 's'.
 * The length is determined by counting the number
 of characters in 's'
 * until the null terminator ('\0') is encountered.
 *
 * @param s Pointer to the null-terminated string.
 * @return The length of the string 's' excluding
 the null terminator.
 *
 * @remark The function correctly handles null
 pointers, returning 0
 *         if 's' is NULL.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

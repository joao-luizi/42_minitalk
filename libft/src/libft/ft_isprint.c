/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:58:44 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:37 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Checks if a given integer represents a printable ASCII character.
 *
 * This function determines whether the specified integer '_C' corresponds
 * to a printable ASCII character. Printable characters are typically
 * defined as characters with ASCII codes ranging from 32 to 126, although
 * sources exclude the space character (ASCII code 32).
 *
 * @param _C The integer to be checked.
 * @return Returns 1 if '_C' represents a printable ASCII character,
 *         otherwise returns 0.
 *
 * @remark This function assumes that the integer '_C' represents a character
 *         encoded using the ASCII character set. It may not provide accurate
 *         results if characters are represented using a different encoding.
 */
int	ft_isprint(int _C)
{
	if (_C >= 32 && _C <= 126)
		return (1);
	return (0);
}

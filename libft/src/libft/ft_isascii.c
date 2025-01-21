/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:07:59 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:32 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Checks if a given integer
 represents an ASCII character.
 *
 * This function determines whether
 the specified integer '_C' falls within
 * the ASCII character range, which
 spans from 0 to 127 inclusive.
 *
 * @param _C The integer to be checked.
 * @return Returns 1 if '_C' represents
 an ASCII character, otherwise returns 0.
 *
 * @remark This function assumes that the
 integer '_C' represents a character
 *         encoded using the ASCII character
 set. It may not provide accurate
 *         results if characters are
 represented using a different encoding
 */
int	ft_isascii(int _C)
{
	if (_C >= 0 && _C <= 127)
		return (1);
	else
		return (0);
}

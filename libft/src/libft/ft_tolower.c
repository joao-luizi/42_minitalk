/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:24:37 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:30 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Converts a uppercase letter
 to its corresponding lowercase letter.
 *
 * This function converts the uppercase
 letter specified by '_C' to its corresponding
 * lowercase letter if it is in the range
 of uppercase letters ('A' to 'A'). If '_C'
 * is not a uppercase letter, it returns
 '_C' unchanged.
 *
 * @param _C The character to be converted
 to lowercase.
 * @return The lowercase equivalent of '_C'
 if it is a uppercase letter,
	otherwise returns '_C' unchanged.
 *
 */
int	ft_tolower(int _C)
{
	if (_C >= 'A' && _C <= 'Z')
		return (_C + 32);
	return (_C);
}

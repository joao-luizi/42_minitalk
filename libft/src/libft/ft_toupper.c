/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:16:08 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:32 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Converts a lowercase letter to
 its corresponding uppercase letter.
 *
 * This function converts the lowercase
 letter specified by '_C' to its corresponding
 * uppercase letter if it is in the range
 of lowercase letters ('a' to 'z'). If '_C'
 * is not a lowercase letter, it returns
 '_C' unchanged.
 *
 * @param _C The character to be converted
 to uppercase.
 * @return The uppercase equivalent of
 '_C' if it is a lowercase letter,
	otherwise returns '_C' unchanged.
 *
 */
int	ft_toupper(int _C)
{
	if (_C >= 'a' && _C <= 'z')
		return (_C - 32);
	return (_C);
}

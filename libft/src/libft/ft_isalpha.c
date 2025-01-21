/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:20:07 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:30 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Determines whether the specified
 character is an alphabetic character.
 *

 * This function checks whether the specified
 integer value corresponds to an alphabetic
 character in the ASCII table.

 * Alphabetic characters include both uppercase
 and lowercase letters from 'A' to 'Z' and from 'a' to 'z'.
 *
 * \param _C The integer value of the character
 to be checked.
 * \return (Returns 1 if the character is alphabetic);
 otherwise, returns 0.
 */
int	ft_isalpha(int _C)
{
	if ((_C >= 'a' && _C <= 'z') || (_C >= 'A' && _C <= 'Z'))
		return (1);
	else
		return (0);
}

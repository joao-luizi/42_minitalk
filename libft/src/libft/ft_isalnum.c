/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:00:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:28 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Checks if a character is alphanumeric.
 *
 * This function determines whether the specified
 character '_C' is alphanumeric,
 * i.e., whether it is either a letter (uppercase
 or lowercase) or a digit.
 * The function returns a non-zero value (true)
 if the character is
 * alphanumeric; otherwise, it returns 0 (false).
 * Calls on `libft.a` functions `ft_isalpha()` and `ft_isdigit()`.
 *
 * @param _C The character to be checked.
 * @return Returns a non-zero value if the character
 is alphanumeric,
	otherwise returns 0.
 *
 * @remark This function relies on the functionalities
 of 'ft_isalpha' and 'ft_isdigit'
 *         to determine if the character is a letter
 or a digit, respectively.
 */
int	ft_isalnum(int _C)
{
	return (ft_isalpha(_C) || ft_isdigit(_C));
}

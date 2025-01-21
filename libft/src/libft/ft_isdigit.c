/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:06:50 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:35 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Checks if a given character
 represents a digit.
 *
 * This function determines whether the
 specified character '_C' corresponds
 * to a digit character in the ASCII
 character set (i.e., '0' to '9').
 *
 * @param _C The character to be checked.
 * @return Returns 1 if '_C' represents
 a digit character, otherwise returns 0.
 *
 */
int	ft_isdigit(int _C)
{
	if (_C >= '0' && _C <= '9')
		return (1);
	else
		return (0);
}

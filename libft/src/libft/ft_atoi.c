/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:30:25 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:20 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Converts a string to an integer.
 *
 * This function mimics the behavior of the standard
 library function atoi().
 * It converts the initial portion of the string
 pointed to by nptr to an integer.
 * The function skips leading whitespace characters
 * and then reads an optional plus or minus sign followed
 by as many numerical digits as possible.
 * If the string begins with a valid sign character ('+' or '-'),
	the sign is recorded,
 * and if there is more than one sign character or a
 non-digit character after a valid sign,
 * the function returns 0. After parsing digits,
 the function stops evaluating characters
 * as soon as it encounters the first non-digit character.
 * Calls `libft.a` function `ft_isdigit()`
 *
 * @param nptr Pointer to the null-terminated string to
 be converted.
 * @return The converted integer value. If nptr does not
 contain a valid integer representation,
 * or if the converted value overflows, the behavior is undefined.
 * If no conversion could be performed, 0 is returned.
 */
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	sign_count;
	int	result;
	int	i;

	sign_count = 0;
	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (++sign_count > 1)
			return (0);
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

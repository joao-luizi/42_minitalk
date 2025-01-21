/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/09 19:35:45 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/**
 * \brief Skips whitespace characters in a string.
 *

	* This function increments the index \p i 
	to skip over any whitespace characters
 * in the string \p str. Whitespace characters 
 include space (32) and characters
 * from horizontal tab (9) to carriage return (13).
 *
 * \param str The string to be checked for 
 * whitespace characters.
 * \param i Pointer to the index that will 
 * be incremented to skip whitespace.
 *
 */
static void	check_whitespace(char *str, int *i)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

/**
 * \brief Checks for sign characters at the 
 * beginning of a string.
 *

	* This function checks for leading sign 
	characters ('-' or '+') in the string \p str

	* and updates the sign and error status 
	accordingly. It increments the index \p i
 * to skip over any sign characters. If multiple
  sign characters are found,
	it sets
 * the error flag to TRUE.
 *
 * \param str The string to be checked for 
 * sign characters.

	* \param i Pointer to the index that will
	 be incremented to skip sign characters.

	* \param error Pointer to an integer that 
	will be set to TRUE if multiple sign characters
	 are found.
 * \param sign Pointer to an integer representing 
 the sign of the number,
	which will be updated based on the sign characters.
 *
 */
static void	check_sign(char *str, int *i, int *error, int *sign)
{
	int	sign_count;

	sign_count = 0;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (++sign_count > 1)
		{
			*error = TRUE;
			break ;
		}
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

/**
 * \brief Converts a string to an integer,
	handling whitespace and sign characters.
 *

	* This function converts the initial 
	portion of the string \p str to an integer,
 * handling leading whitespace and sign 
 characters. It sets the \p error flag if
 * the input string is invalid or if the 
 resulting integer would overflow.
 *
 * \param str The string to be converted 
 * to an integer.

	* \param error Pointer to an integer 
	that will be set to TRUE if an error occurs.
 *
 * \return The converted integer value, 
 * or 0 if an error occurs.
 *
 * \note If \p str or \p error is a null pointer,
	the function returns immediately.
 */
int	custom_atoi(char *str, int *error)
{
	int		sign;
	long	result;
	int		i;

	if (!str || !error)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	check_whitespace(str, &i);
	check_sign(str, &i, error, &sign);
	if (str[i] == '\0' || sign < 0)
		*error = TRUE;
	while (ft_isdigit(str[i]) && !*error)
	{
		result = result * 10 + (str[i++] - '0');
		if (sign > 0 && result > INT_MAX)
			*error = TRUE;
		if (sign < 0 && result * -1 < INT_MIN)
			*error = TRUE;
	}
	if (str[i] != '\0')
		*error = TRUE;
	return ((int)(result * sign));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:56:37 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:40 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Converts an unsigned integer to a
 * string representation.
 *
 * This function converts the given unsigned
 * integer 'number' into its string
 * representation and stores it in the provided
 * buffer 'buffer'. The resulting
 * string is terminated by a null character
 * ('\0'). If the integer is 0, the
 * resulting string will be "0". If 'sign' is
 * negative, a minus sign ('-') is
 * prepended to the string. The parameter
 * 'capacity' specifies the maximum
 * number of characters that can be written
 * to 'buffer', including the null
 * terminator. The actual length of the resulting
 *  string can be up to one
 * character longer than 'capacity' to
 * accommodate the minus sign.
 *
 * @param buffer A pointer to the buffer where
 * the string representation will be stored.
 * @param number The unsigned integer to be
 * converted to a string.
 * @param sign The sign of the integer. If
 * negative, a minus sign is prepended to the string.
 * @param capacity The maximum capacity of
 * the buffer, including the null terminator.
 * @return A pointer to the resulting string
 *  stored in 'buffer'.
 */
static char	*ft_inner_itoa(char *buffer, unsigned int number, int sign,
		size_t capacity)
{
	int	i;

	i = 0;
	if (number == 0)
		*(buffer + i) = '0';
	while (number > 0)
	{
		*(buffer + (capacity - i)) = (number % 10) + '0';
		number = number / 10;
		i++;
	}
	if (sign < 0)
		*(buffer + (capacity - i)) = '-';
	*(buffer + (capacity + 1)) = '\0';
	return (buffer);
}

/**
 *
 * @brief Counts the number of characters required
 * to represent an unsigned integer and its sign.
 *
 * This function calculates the number of characters
 * needed to represent the given unsigned integer 'n'
 * and its sign. If 'n' is 0, the function returns 1.
 *  Otherwise, it iteratively divides 'n' by 10 and
 * increments the count until 'n' becomes 0. If the
 *  'sign' parameter is negative, an additional character
 * is added to account for the minus sign ('-'). The
 *  resulting count includes the digits of the number
 * and the sign character if applicable.
 *
 * @param n The unsigned integer for which the
 * character count is calculated.
 * @param sign The sign of the integer. If negative,
 *  an additional character is added for the minus sign.
 * @return The total number of characters required
 *  to represent the integer and its sign.
 */
static int	count_chars(unsigned int n, int sign)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	if (sign < 0)
		count++;
	return (count);
}

/**
 * \brief Converts an integer to a
 string representation.
 *
 * \param n The integer to convert.
 * \return A dynamically allocated string
 representing the integer (or NULL if an error occurs)
 *
 */
char	*ft_itoa(int n)
{
	char			*buffer;
	int				sign;
	size_t			capacity;
	unsigned int	safe_n;

	sign = 1;
	if (n < 0)
		sign = -1;
	safe_n = n * sign;
	capacity = count_chars(safe_n, sign);
	buffer = malloc(capacity + 1);
	if (buffer == NULL)
		return (NULL);
	buffer = ft_inner_itoa(buffer, safe_n, sign, capacity - 1);
	return (buffer);
}

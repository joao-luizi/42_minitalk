/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:55:15 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:22 by joaomigu         ###   ########.fr       */
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
static void	ft_inner_itoa(int fd, unsigned int number)
{
	char	c;

	if (number == 0)
		write(fd, "0", 1);
	else
	{
		if (number >= 10)
		{
			ft_inner_itoa(fd, number / 10);
			ft_inner_itoa(fd, number % 10);
		}
		else
		{
			c = number % 10 + '0';
			write(fd, &c, 1);
		}
	}
}

/**
	* \brief Writes a string representing
	an integer to a file descriptor.
	*
	* \param n The number to write.
	* \param fd The file descriptor to which
	the string will be written.
	* \return None
	*
	*/
void	ft_putnbr_fd(int n, int fd)
{
	int				sign;
	unsigned int	safe_n;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	safe_n = n * sign;
	ft_inner_itoa(fd, safe_n);
}

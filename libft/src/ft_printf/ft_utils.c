/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:40:16 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/11 14:28:58 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Calculates the length of the string
 *  needed to represent an integer in a specified base.
 *
 * This function calculates the number of 
 * characters required to represent a given
 * integer in the specified base. It counts how
 *  many times the absolute value of
 * the number can be divided by the length of 
 * the base until it reaches zero.
 *
 * @param nbr The integer to be converted.
 * @param base_to The target base as a string.
 * @return size_t The number of characters needed
 *  to represent the integer in the specified base.
 */
size_t	ft_inbrlen(int nbr, char *base_to)
{
	int				count;
	unsigned int	safe_nbr;
	size_t			base_len;

	base_len = ft_strlen(base_to);
	count = 0;
	if (nbr < 0)
		safe_nbr = nbr * -1;
	else
		safe_nbr = nbr;
	if (safe_nbr == 0)
		count++;
	else
	{
		while (safe_nbr > 0)
		{
			safe_nbr /= base_len;
			count++;
		}
	}
	return (count);
}

/**
 * @brief Calculates the length of the string needed
 *  to represent a long integer in a specified base.
 *
 * This function calculates the number of characters
 *  required to represent a given
 * long integer in the specified base. It counts how
 *  many times the number can be divided
 * by the length of the base until it reaches zero.
 *
 * @param nbr The long integer to be converted.
 * @param base_to The target base as a string.
 * @return size_t The number of characters needed to
 *  represent the long integer in the specified base.
 */
size_t	ft_lnbrlen(long nbr, char *base_to)
{
	int				count;
	size_t			base_len;

	base_len = ft_strlen(base_to);
	count = 0;
	if (nbr == 0)
		count++;
	else
	{
		while (nbr != 0)
		{
			nbr /= base_len;
			count++;
		}
	}
	return (count);
}

/**
 * @brief Validates a base string for numeric 
 * conversions.
 *
 * This function checks if a given base string 
 * is valid for use in numeric
 * conversions. A valid base string must not 
 * contain '+', '-', or whitespace
 * characters, and each character in the base 
 * must be unique. Additionally,
 * the base string must contain at least two 
 * characters.
 *
 * @param base The base string to be validated.
 * @return int The length of the base if valid, 
 * or 0 if the base is invalid.
 */
static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-' || ft_iswhitespace(base[i]) == 1)
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

/**
 * @brief Converts an integer to a specified base 
 * and returns the result as a string.
 *
 * This function converts an integer value to its 
 * string representation in the
 * specified base. It first checks if the base is 
 * valid using the check_base function,
 * then allocates memory for the resulting string, 
 * and finally populates the string
 * with the converted value.
 *
 * @param nbr The integer to be converted.
 * @param base_to The target base as a string.
 * @return char* The string representation of the 
 * integer in the specified base.
 *         Returns NULL if the base is invalid or 
 * memory allocation fails.
 */
char	*ft_itoabase(int nbr, char *base_to)
{
	char	*buffer;
	size_t	char_count;
	int		len_base_to;

	len_base_to = check_base(base_to);
	if (len_base_to == 0)
		return (NULL);
	char_count = ft_inbrlen(nbr, base_to);
	buffer = malloc(char_count + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[char_count] = '\0';
	i_number_tobuffer(nbr, base_to, char_count, buffer);
	return (buffer);
}

/**
 * @brief Converts a long integer to a specified
 *  base and returns the result as a string.
 *
 * This function converts a long integer value to
 *  its string representation in the
 * specified base. It first checks if the base is
 *  valid using the check_base function,
 * then allocates memory for the resulting string,
 *  and finally populates the string
 * with the converted value.
 *
 * @param nbr The long integer to be converted.
 * @param base_to The target base as a string.
 * @return char* The string representation of the 
 * long integer in the specified base.
 *         Returns NULL if the base is invalid or 
 * memory allocation fails.
 */
char	*ft_utoabase(long nbr, char *base_to)
{
	char	*buffer;
	size_t	char_count;
	int		len_base_to;

	len_base_to = check_base(base_to);
	if (len_base_to == 0)
		return (NULL);
	char_count = ft_lnbrlen(nbr, base_to);
	buffer = malloc(char_count + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[char_count] = '\0';
	l_number_tobuffer(nbr, base_to, char_count, buffer);
	return (buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:12:39 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:12:39 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Checks if a given character is a 
 * whitespace character.
 *
 * This function checks if the given character
 *  is a whitespace character according to ASCII standards.
 * Whitespace characters include space (ASCII 32)
 *  and control characters like tab (ASCII 9),
 * newline (ASCII 10), vertical tab (ASCII 11), 
 * form feed (ASCII 12), and carriage return (ASCII 13).
 *
 * @param c The character to be checked.
 * @return int Returns TRUE (1) if the character 
 * is a whitespace character, FALSE (0) otherwise.
 */
int	ft_iswhitespace(char c)
{
	if ((c == 32 || (c >= 9 && c <= 13)))
		return (TRUE);
	else
		return (FALSE);
}

/**
 * @brief Checks if a given character is found in 
 * a string (the same could be achieved with ft_strchr).
 *
 * This function iterates through the characters of the given string to check
 * if the specified character is present. It returns 
 * TRUE (1) if the character is found,
 * and FALSE (0) otherwise.
 *
 * @param lst The string to search within.
 * @param c The character to be searched for.
 * @return int Returns TRUE (1) if the character is 
 * found in the string, FALSE (0) otherwise.
 */
int	ft_ischarinlist(char *lst, char c)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		if (lst[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/**
 * @brief Converts an integer value to a string 
 * representation and places it in a buffer.
 *
 * This function converts the given integer value to 
 * its string representation using the specified base.
 * It places each character representing the digits of 
 * the integer in the buffer, starting from the end of the buffer.
 *
 * @param nbr The integer value to be converted.
 * @param base The base for conversion as a string.
 * @param bf_size The size of the buffer.
 * @param bf The buffer to store the string representation
 *  of the integer.
 */
void	i_number_tobuffer(int nbr, char *base, int bf_size, char *bf)
{
	unsigned int	safe_nbr;
	size_t			base_size;

	base_size = ft_strlen(base);
	if (nbr < 0)
		safe_nbr = nbr * -1;
	else
		safe_nbr = nbr;
	if (safe_nbr == 0)
	{
		bf[bf_size - 1] = base[safe_nbr % base_size];
		bf_size--;
	}
	while (safe_nbr != 0)
	{
		bf[bf_size - 1] = base[safe_nbr % base_size];
		safe_nbr = safe_nbr / base_size;
		bf_size--;
	}
}

/**
 * @brief Converts a long integer value to a string 
 * representation and places it in a buffer.
 *
 * This function converts the given long integer value 
 * to its string representation using the specified base.
 * It places each character representing the digits of 
 * the integer in the buffer, starting from the end of the buffer.
 *
 * @param nbr The long integer value to be converted.
 * @param base The base for conversion as a string.
 * @param bf_size The size of the buffer.
 * @param bf The buffer to store the string representation
 *  of the long integer.
 */
void	l_number_tobuffer(long nbr, char *base, int bf_size, char *bf)
{
	size_t	base_size;

	base_size = ft_strlen(base);
	if (nbr == 0)
	{
		bf[bf_size - 1] = base[nbr % base_size];
		bf_size--;
	}
	while (nbr != 0)
	{
		bf[bf_size - 1] = base[nbr % base_size];
		nbr = nbr / base_size;
		bf_size--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:23:22 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:23:22 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Checks and sets a flag based
 *  on the input character.
 *
 * This function checks if a given character
 *  corresponds to a flag and sets 
 * the corresponding bit in the flags 
 * variable if it is not already set. 
 * It uses an enum to determine the bit 
 * position for each flag.
 *
 * @param flags Pointer to the integer 
 * variable that stores the flags.
 * @param c The character to check and set
 *  as a flag.
 *
 * @return TRUE if the flag was successfully
 *  set, FALSE if the flag was already set or the character is not a valid flag.
 */
static int	check_flag(char *flags, char c)
{
	int	enum_flag;

	enum_flag = 0;
	if (c == '-')
		enum_flag = MINUS;
	else if (c == '+')
		enum_flag = PLUS;
	else if (c == ' ')
		enum_flag = SPACE;
	else if (c == '#')
		enum_flag = CARDINAL;
	else if (c == '0')
		enum_flag = ZERO;
	else
		return (FALSE);
	*flags |= enum_flag;
	return (TRUE);
}

/**
 * @brief Iterates through a string to 
 * set format flags.
 *
 * This function iterates through the given
 *  string starting at the index pointed 
 * to by the integer pointer. It sets the 
 * corresponding flags if the characters 
 * are valid format flags. The function stops
 *  when it encounters a character 
 * that is not a valid flag.
 *
 * @param str The string to iterate through.
 * @param i Pointer to the current index in the string.
 *
 * @return A char representing the flags set.
 *  Returns -1 if an invalid flag combination is encountered.
 */
char	get_flags(char *str, int *i)
{
	char	flags;

	flags = 0;
	while (str[*i])
	{
		if (!ft_ischarinlist("-0# +", str[*i]))
			break ;
		if (!check_flag(&flags, str[*i]))
		{
			flags = -1;
			break ;
		}
		*i += 1;
	}
	return (flags);
}

/**
 * @brief Parses the width from the format string.
 *
 * This function parses the width from the 
 * given format string, handling both 
 * direct numeric widths and the '*' character
 *  which indicates that the width 
 * should be obtained from the variable argument
 *  list.
 *
 * @param str The format string to parse.
 * @param args The variable argument list to 
 * extract width if '*' is encountered.
 * @param i Pointer to the current index in the
 *  format string.
 *
 * @return The parsed width as an integer. Returns
 *  0 if no width is specified.
 */
int	get_width(char *str, va_list *args, int *i)
{
	int	result;

	if (!str)
		return (0);
	if (!ft_isdigit(*(str + *i)) && !(*(str + *i) == '*'))
		result = 0;
	else
	{
		if (*(str + *i) == '*')
		{
			result = va_arg(*args, int);
			*i += 1;
		}
		else
		{
			result = ft_atoi((str + *i));
			*i += ft_inbrlen(result, "0123456789");
		}
	}
	return (result);
}

/**
 * @brief Parses the precision from the 
 * format string.
 *
 * This function parses the precision from
 *  the given format string, handling both
 * direct numeric precisions and the '*' 
 * character which indicates that the precision
 * should be obtained from the variable 
 * argument list. If no precision is specified,
 * it defaults to -1.
 *
 * @param str The format string to parse.
 * @param args The variable argument list 
 * to extract precision if '*' is encountered.
 * @param i Pointer to the current index in
 *  the format string.
 *
 * @return The parsed precision as an 
 * integer. Returns -1 if no precision is
 *  specified.
 */
int	get_precision(char *str, va_list *args, int *i)
{
	int	result;

	if (!str)
		return (-1);
	if (*(str + *i) != '.')
		result = -1;
	else
	{
		*i += 1;
		if (*(str + *i) == '*')
		{
			result = va_arg(*args, int);
			*i += 1;
		}
		else
		{
			result = ft_atoi((str + *i));
			*i += ft_inbrlen(result, "0123456789") - 1;
		}
	}
	return (result);
}

/**
 * @brief Determines the final width based 
 * on precision, width, and character count.
 *
 * This function calculates the final width 
 * for printing by comparing the specified
 * precision, width, and the actual number 
 * of characters needed. It returns the largest
 * applicable value, ensuring the output 
 * field width is correctly formatted.
 *
 * @param precision The specified precision
 *  for the field width.
 * @param width The specified minimum width
 *  for the field.
 * @param char_count The actual number of 
 * characters required for the output.
 *
 * @return The final width to be used for the
 *  output field.
 */
size_t	get_final_width(int precision, int width, int char_count)
{
	size_t	max;

	max = 0;
	if (char_count >= 0 && char_count > width)
		max = char_count;
	if (precision >= 0 && precision < char_count)
		max = precision;
	if (width >= 0 && width > (int)max)
		max = width;
	return (max);
}

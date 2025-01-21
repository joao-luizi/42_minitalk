/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:26:16 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:26:16 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Prepends characters to the 
 * string based on formatting information.
 * 
 * @param str A pointer to a pointer 
 * to the string to which characters 
 * are prepended.
 * @param info A pointer to a structure
 *  containing formatting information.
 */

static	void	str_prepend(char **str, t_info *info)
{
	int		remaining;
	size_t	nbr_len;
	int		i;

	i = 0;
	nbr_len = ft_strlen(*str);
	if (info->precision > 0 || info->flags & ZERO)
	{
		if (info->precision > 0)
			remaining = info->precision - nbr_len;
		else
		{
			if (info->flags > 0 && info->flags & CARDINAL)
				remaining = info->width - nbr_len - 2;
			else
				remaining = info->width - nbr_len;
		}
		while (i < remaining)
		{
			(*str) = ft_prepend("0", (*str));
			i++;
		}
	}
}

/**
 * @brief Extracts the argument from a va_list
 *  and converts it to a string for the x and X format specifier.
 * 
 * @param info A pointer to a structure containing formatting information.
 * @param args A pointer to a va_list of arguments.
 * @param c The format specifier character ('x' or 'X').
 * @return A pointer to the resulting string.
 */
static char	*extract_arg(t_info *info, va_list *args, char c)
{
	int		arg;
	char	*nbr;

	arg = va_arg(*args, int);
	if (!arg)
		arg = 0;
	if (info->precision == 0 && arg == 0)
		nbr = ft_strdup("");
	else if (info->precision < 0 && arg == 0
		&& info->flags > 0 && !(info->flags & ZERO))
		nbr = ft_strdup("0");
	else
	{
		if (c == 'x')
			nbr = x_get_string_number(info, arg, "0123456789abcdef", c);
		else
			nbr = x_get_string_number(info, arg, "0123456789ABCDEF", c);
	}
	return (nbr);
}

/**
 * @brief Gets the string representation of a
 *  number for the x and X format specifier.
 * 
 * @param info A pointer to a structure containing formatting information.
 * @param nbr The number to convert to a string.
 * @param base The base for conversion (e.g.,
 *  "0123456789abcdef" for hexadecimal).
 * @param c The format specifier character ('x' or 'X').
 * @return A pointer to the resulting string.
 */
char	*x_get_string_number(t_info *info, unsigned int nbr, char *base, char c)
{
	char	*str;

	str = ft_utoabase(nbr, base);
	str_prepend(&str, info);
	if (info->flags > 0)
	{
		if (info->flags & CARDINAL && nbr != 0)
		{
			if (c == 'X')
				str = ft_prepend("0X", str);
			else
				str = ft_prepend("0x", str);
		}
	}
	return (str);
}

/**
 * @brief Handles the creation of the final
 *  string for the x and X format specifier.
 * 
 * @param info A pointer to a structure 
 * containing formatting information.
 * @param args A pointer to a va_list of arguments.
 * @param c The format specifier character 
 * ('x' or 'X').
 * @return A pointer to the resulting string.
 */
char	*x_handler(t_info *info, va_list *args, char c)
{
	char		*nbr;
	char		*result_str;
	size_t		char_count;
	size_t		min_width;

	nbr = extract_arg(info, args, c);
	char_count = ft_strlen(nbr);
	if ((int)char_count > info->precision)
		info->precision = (int)char_count;
	min_width = get_final_width(info->precision, info->width, char_count);
	if (info->precision < 0)
		info->precision = (int)char_count;
	else if (info->precision > (int)char_count)
		info->precision = (int)char_count;
	result_str = final_string(nbr, min_width, info->precision, info);
	info->str_len = min_width;
	free(nbr);
	return (result_str);
}

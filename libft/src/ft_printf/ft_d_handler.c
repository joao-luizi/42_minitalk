/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:41:52 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 14:41:52 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Prepends characters to the string based
 *  on formatting information for the d format specifier.
 * 
 * @param nbr The integer number being 
 * converted.
 * @param str A pointer to a pointer to the 
 * string to which characters are prepended.
 * @param info A pointer to a structure containing 
 * formatting information.
 */
static void	str_prepend(int nbr, char **str, t_info *info)
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
			if (nbr < 0)
				nbr_len++;
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
 * @brief Gets the string representation 
 * of an integer for the d format specifier.
 * 
 * @param info A pointer to a structure 
 * containing formatting information.
 * @param nbr The integer number to convert 
 * to a string.
 * @param base The base for conversion (e.g., 
 * "0123456789" for decimal).
 * @return A pointer to the resulting string.
 */
static char	*get_string_number(t_info *info, int nbr, char *base)
{
	char	*str;

	str = ft_itoabase(nbr, base);
	str_prepend(nbr, &str, info);
	if (nbr >= 0)
	{
		if (info->flags & PLUS && info->flags > 0)
			str = ft_prepend("+", str);
		else if (info->flags & SPACE && info->flags > 0)
			str = ft_prepend(" ", str);
	}
	else
		str = ft_prepend("-", str);
	return (str);
}

/**
 * @brief Extracts the argument from a va_list 
 * and converts it to a string for the d format specifier.
 * 
 * @param info A pointer to a structure containing 
 * formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
static char	*extract_arg(t_info *info, va_list *args)
{
	int			arg;
	char		*nbr;

	arg = va_arg(*args, int);
	if (!arg)
		arg = 0;
	if (info->precision == 0 && arg == 0)
		nbr = ft_strdup("");
	else
		nbr = get_string_number(info, arg, "0123456789");
	return (nbr);
}

/**
 * @brief Handles the creation of the final string for the d format specifier.
 * 
 * @param info A pointer to a structure containing formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
char	*d_handler(t_info *info, va_list *args)
{
	char	*nbr;
	char	*result_str;
	size_t	char_count;
	size_t	min_width;

	nbr = extract_arg(info, args);
	char_count = ft_strlen(nbr);
	if ((int)char_count > info->precision)
		info->precision = char_count;
	min_width = get_final_width(info->precision, info->width, char_count);
	if (info->precision < 0)
		info->precision = char_count;
	else if (info->precision > (int)char_count)
		info->precision = (int)char_count;
	if (info->flags > 0 && info->flags & ZERO)
		info->padding = '0';
	result_str = final_string(nbr, min_width, info->precision, info);
	info->str_len = ft_strlen(result_str);
	free(nbr);
	return (result_str);
}

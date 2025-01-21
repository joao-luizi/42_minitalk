/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:02 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 14:42:02 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Prepends characters to the 
 * string based on formatting information for the p format specifier.
 * 
 * @param nbr The pointer value being 
 * converted.
 * @param str A pointer to a pointer to 
 * the string to which characters are prepended.
 * @param info A pointer to a structure 
 * containing formatting information.
 */
static void	str_prepend(char **str, t_info *info)
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
			remaining = info->width - nbr_len - 2;
		while (i < remaining)
		{
			(*str) = ft_prepend("0", (*str));
			i++;
		}
	}
}

/**
 * @brief Gets the string representation 
 * of a pointer for the p format specifier.
 * 
 * @param info A pointer to a structure 
 * containing formatting information.
 * @param nbr The pointer value to convert 
 * to a string.
 * @param base The base for conversion (e.g.
 * , "0123456789abcdef" for hexadecimal).
 * @return A pointer to the resulting string.
 */
static char	*p_get_string_number(t_info *info, long nbr, char *base)
{
	char	*str;

	str = ft_utoabase(nbr, base);
	str_prepend(&str, info);
	if (info->flags < 0)
		str = ft_prepend("0x", str);
	else if (info->flags & PLUS)
		str = ft_prepend("+0x", str);
	else if (info->flags & SPACE)
		str = ft_prepend(" 0x", str);
	else
		str = ft_prepend("0x", str);
	return (str);
}

/**
 * @brief Extracts the argument from a va_list 
 * and converts it to a string for the p format 
 * specifier.
 * 
 * @param info A pointer to a structure containing 
 * formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
static char	*extract_arg(t_info *info, va_list *args)
{
	long	arg;
	char	*nbr;

	arg = va_arg(*args, long);
	if (!arg)
		nbr = ft_strdup("(nil)");
	else
		nbr = p_get_string_number(info, arg, "0123456789abcdef");
	return (nbr);
}

/**
 * @brief Handles the creation of the final 
 * string for the p format specifier.
 * 
 * @param info A pointer to a structure containing
 *  formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
char	*p_handler(t_info *info, va_list *args)
{
	char	*nbr;
	char	*result_str;
	size_t	char_count;
	size_t	min_width;

	nbr = extract_arg(info, args);
	char_count = ft_strlen(nbr);
	if ((int)char_count > info->precision)
		info->precision = (int)char_count;
	min_width = get_final_width(info->precision, info->width, char_count);
	if (info->precision < 0)
		info->precision = char_count;
	else if (info->precision > (int)char_count)
		info->precision = (int)char_count;
	result_str = final_string(nbr, min_width, info->precision, info);
	info->str_len = min_width;
	free(nbr);
	return (result_str);
}

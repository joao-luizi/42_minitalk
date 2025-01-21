/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:09:34 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:09:34 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Gets the string representation 
 * of an unsigned number for the u format specifier.
 * 
 * @param info A pointer to a structure 
 * containing formatting information.
 * @param nbr The unsigned number to convert 
 * to a string.
 * @param base The base for conversion (e.g., 
 * "0123456789" for decimal).
 * @return A pointer to the resulting string.
 */
static char	*u_get_string_number(t_info *info, unsigned int nbr, char *base)
{
	char	*str;
	int		i;
	size_t	nbr_len;
	int		remaining;

	str = ft_utoabase(nbr, base);
	i = 0;
	nbr_len = ft_strlen(str);
	if (info->precision > 0 || info->flags & ZERO)
	{
		if (info->precision > 0)
			remaining = info->precision - nbr_len;
		else
			remaining = info->width - nbr_len - 1;
		while (i < remaining)
		{
			str = ft_prepend("0", str);
			i++;
		}
	}
	return (str);
}

/**
 * @brief Extracts the argument from a va_list 
 * and converts it to a string for the u format 
 * specifier.
 * 
 * @param info A pointer to a structure containing 
 * formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
static char	*extract_arg(t_info *info, va_list *args)
{
	int		arg;
	char	*nbr;

	arg = va_arg(*args, int);
	if (!arg)
		arg = 0;
	if (info->precision == 0 && arg == 0)
		nbr = ft_strdup("");
	else
		nbr = u_get_string_number(info, arg, "0123456789");
	return (nbr);
}

/**
 * @brief Handles the creation of the final 
 * string for the u format specifier.
 * 
 * @param info A pointer to a structure containing
 *  formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
char	*u_handler(t_info *info, va_list *args)
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
	if (info->flags > 0 && info->flags & ZERO)
		info->padding = '0';
	result_str = final_string(nbr, min_width, info->precision, info);
	info->str_len = min_width;
	free(nbr);
	return (result_str);
}

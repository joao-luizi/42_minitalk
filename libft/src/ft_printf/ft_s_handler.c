/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:09:18 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:09:18 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Extracts the argument from a 
 * va_list and converts it to a string for the s format specifier.
 * 
 * @param info A pointer to a structure 
 * containing formatting information.
 * @param args A pointer to a va_list of 
 * arguments.
 * @return A pointer to the resulting string.
 */
static char	*extract_arg(t_info *info, va_list *args)
{
	char	*str;
	char	*arg;

	arg = va_arg(*args, char *);
	if (!arg)
	{
		if (info->precision >= 0)
		{
			if (info->precision >= 6)
				str = ft_strdup("(null)");
			else
				str = ft_strdup("");
		}
		else
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(arg);
	return (str);
}

/**
 * @brief Handles the creation of the final 
 * string for the s format specifier.
 * 
 * @param info A pointer to a structure 
 * containing formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
char	*s_handler(t_info *info, va_list *args)
{
	char	*result_str;
	size_t	char_count;
	size_t	min_width;
	char	*str;

	str = extract_arg(info, args);
	char_count = ft_strlen(str);
	min_width = get_final_width(info->precision, info->width, char_count);
	if (info->precision < 0)
		info->precision = (int)char_count;
	else if (info->precision > (int)char_count)
		info->precision = char_count;
	result_str = final_string(str, min_width, info->precision, info);
	info->str_len = min_width;
	free(str);
	return (result_str);
}

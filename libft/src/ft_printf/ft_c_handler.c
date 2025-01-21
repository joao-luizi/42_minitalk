/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:41:41 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 14:41:41 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Handles the creation of the final string for the c format specifier.
 * 
 * @param info A pointer to a structure containing formatting information.
 * @param args A pointer to a va_list of arguments.
 * @return A pointer to the resulting string.
 */
char	*c_handler(t_info *info, va_list *args)
{
	char	*p;
	int		len;
	char	c;

	len = 0;
	if (info->width >= 0)
		len = info->width;
	if (len < 1)
		len = 1;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	ft_memset(p, ' ', len);
	info->str_len = len;
	c = va_arg(*args, unsigned int);
	if (info->flags & MINUS)
		p[0] = c;
	else
		p[len - 1] = c;
	p[len] = '\0';
	return (p);
}

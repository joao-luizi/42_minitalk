/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:21:52 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:21:52 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Populates the t_info struct
 *  with default values.
 *
 * This function initializes the members
 *  of the t_info struct with default values.
 * It sets the flags to -1, width to 0,
 *  precision to -1, padding to space (' '), and
 * string length to the specified length.
 *
 * @param info A pointer to the t_info 
 * struct to be populated.
 * @param len The string length to be 
 * assigned to the struct.
 */
static void	default_info(t_info *info, size_t len)
{
	info->flags = -1;
	info->width = 0;
	info->precision = -1;
	info->padding = ' ';
	info->str_len = len;
}

/**
 * @brief Checks the information node for
 *  exclusive conditions.
 *
 * This function checks the information node
 *  represented by the t_info struct
 * for exclusive conditions, such as the 
 * presence of a ZERO and MINUS flag,
 * precision and ZERO flag, or a negative width.
 *  It adjusts the flags accordingly.
 *
 * @param info A pointer to the t_info struct to be checked and adjusted.
 */
static void	check_info(t_info *info)
{
	if (info->width < 0)
	{
		info->width *= -1;
		info->flags |= MINUS;
	}
	if (info->flags > 0)
	{
		if (info->flags & ZERO && info->flags & MINUS)
			info->flags = info->flags ^ ZERO;
		if (info->precision >= 0 && info->flags & ZERO)
			info->flags = info->flags ^ ZERO;
	}
}

/**
 * @brief Populates the t_info struct based on
 *  the format string and arguments.
 *
 * This function populates the t_info struct with
 *  information obtained from the format string
 * and arguments list. It initializes the flags,
 *  width, precision, padding, and string length
 * members of the struct based on the specifier found in the format string.
 *
 * @param info A pointer to the t_info struct to
 *  be populated.
 * @param content The format string containing 
 * the format specifier.
 * @param args A pointer to the arguments list.
 */
void	format_info(t_info *info, char *content, va_list *args)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(content);
	if (info->specifier == NONE)
		default_info(info, len);
	else if (info->specifier == ERROR)
		default_info(info, 0);
	else
	{
		i++;
		info->flags = get_flags(content, &i);
		info->width = get_width(content, args, &i);
		info->precision = get_precision(content, args, &i);
		info->padding = ' ';
		info->str_len = 0;
		check_info(info);
	}
}

/**
 * @brief Copies the contents of the original string
 *  and appends it to another string.
 *
 * This function copies the contents of the original
 *  string and appends it to another string.
 * It checks for the validity of both strings and 
 * allocates memory for the resulting string.
 *
 * @param str The string to which the original 
 * string will be appended.
 * @param original The original string to be copied
 *  and appended.
 * @param result The resulting string after the 
 * operation.
 */
static void	ft_prepend_copy(char *str, char *original, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		(*result)[i] = str[i];
		i++;
	}
	while (original[j])
	{
		(*result)[i] = original[j];
		i++;
		j++;
	}
}

/**
 * @brief Prepends the contents of the original string
 *  to another string.
 *
 * This function prepends the contents of the original
 *  string to another string.
 * It checks for the validity of both strings and 
 * allocates memory for the resulting string.
 * It also frees the original string after the operation.
 *
 * @param str The string to which the original string
 *  will be prepended.
 * @param original The original string to be prepended.
 * @return char* A pointer to the resulting string, or
 *  NULL if memory allocation fails.
 */
char	*ft_prepend(char *str, char *original)
{
	int		str_size;
	int		ori_size;
	char	*result;

	if (!original && !str)
		return (NULL);
	if (!str)
		return (original);
	if (!original)
		return (str);
	str_size = ft_strlen(str);
	ori_size = ft_strlen(original);
	result = malloc(sizeof(char) * (str_size + ori_size + 1));
	if (!result)
		return (NULL);
	result[str_size + ori_size] = '\0';
	ft_prepend_copy(str, original, &result);
	free(original);
	return (result);
}

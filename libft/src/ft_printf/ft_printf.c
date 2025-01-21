/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:08 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 14:42:08 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Get the formatted string based 
 * on the specifier.
 *
 * This function returns a formatted string
 *  based on the specifier found in the
 * t_info struct. Returns the string formatted
 *  according to the specifier.
 *
 * @param info Pointer to the t_info struct 
 * containing the specifier information.
 * @param content The original dynamically 
 * allocated string content.
 * @param args Pointer to the va_list of 
 * arguments.
 * @return char* The formatted string based 
 * on the specifier.
 */
char	*get_specifier_string(t_info *info, va_list *args)
{
	if (info->specifier == pc)
	{
		info->str_len = 1;
		return (ft_strdup("%"));
	}
	else if (info->specifier == c)
		return (c_handler(info, args));
	else if (info->specifier == s)
		return (s_handler(info, args));
	else if (info->specifier == p)
		return (p_handler(info, args));
	else if (info->specifier == d)
		return (d_handler(info, args));
	else if (info->specifier == i)
		return (d_handler(info, args));
	else if (info->specifier == u)
		return (u_handler(info, args));
	else if (info->specifier == x)
		return (x_handler(info, args, 'x'));
	else if (info->specifier == X)
		return (x_handler(info, args, 'X'));
	else
		return (NULL);
}

/**
 * @brief Get the formatted string based 
 * on the specifier.
 *
 * This function returns a formatted string 
 * based on the specifier found in the
 * t_info struct. If the specifier is ERROR 
 * or NONE, it returns the original
 * content. For other specifiers, it frees 
 * the original content and returns the
 * string formatted according to the specifier.
 *
 * @param info Pointer to the t_info struct 
 * containing the specifier information.
 * @param content The original dynamically 
 * allocated string content.
 * @param args Pointer to the va_list of 
 * arguments.
 * @return char* The formatted string based 
 * on the specifier.
 * - If the specifier is ERROR or NONE, returns
 *  the original content.
 * - For other specifiers, returns the string 
 * retured by `get_specifier_string`
 */
char	*get_formatted_string(t_info *info, char *content, va_list *args)
{
	if (info->specifier == ERROR)
		return (content);
	else if (info->specifier == NONE)
		return (content);
	else
	{
		free(content);
		return (get_specifier_string(info, args));
	}
}

/**
 * @brief Parses a string into a token node.
 *
 * This function receives a string and a va_list, 
 * parses the string, and
 * creates a new node when the right conditions
 *  are met (either a format 
 * node or a plain text node). It advances the 
 * string pointer using pointer arithmetic.
 *
 * @param str A pointer to the string to be 
 * parsed. The pointer is advanced 
 *            to the beginning of the remaining 
 * string after a token is extracted.
 * @param args A pointer to the va_list 
 * initialized in ft_printf.
 * @return A new token node. Returns NULL on 
 * memory allocation error or if no token is created.
 */
static	t_info_list	*get_tokens(char **str, va_list *args)
{
	int			i;
	t_info_list	*new;

	i = 0;
	if (*((*str) + i) != '%')
		while (*((*str) + i) && (*((*str) + i) != '%'))
			i++;
	else
	{
		i++;
		while (*((*str) + i) && !ft_ischarinlist("cspdiuxX%",*((*str) + i)))
			i++;
		if (*((*str) + i))
			i++;
	}
	new = get_new_lst(ft_substr(*str, 0, i), args);
	if (!new)
		return (NULL);
	(*str) += i;
	return (new);
}

/**
 * @brief Parses a format string into a 
 * linked list of tokens.
 *
 * This function receives a format string
 *  and a va_list, parses the 
 * format string into nodes (tokens), and
 *  returns a linked list of these tokens.
 *
 * @param str The format string to be parsed.
 * @param args A pointer to the va_list 
 * initialized in ft_printf.
 * @return A linked list of tokens. Returns 
 * NULL if parsing fails or on memory allocation error.
 */
static t_info_list	*ft_tokenizer(char *str, va_list *args)
{
	t_info_list	*t;
	t_info_list	*new;

	t = NULL;
	new = NULL;
	while (*str)
	{
		new = get_tokens(&str, args);
		if (!new)
		{
			free_list(&t);
			return (t);
		}
		ft_info_lst_add_back(&t, new);
	}
	return (t);
}

/**
 * @brief ft_printf - Mimics the C library 
 * function printf.
 * Parses the format string into tokens that 
 * can either be text or 
 * format specifiers. Each token is processed 
 * and printed accordingly.
 * @param format: A format string containing 
 * text and format specifiers.
 * @param ...: A variable number of arguments 
 * to be formatted and printed.
 *
 *
 * @eturn: The total number of characters printed, or -1 on error.
 */
int	ft_printf(const char *format, ...)
{
	size_t		result;
	va_list		args;
	t_info_list	*tokens;

	tokens = NULL;
	result = 0;
	if (!format)
		return (-1);
	if (format[0] == '\0')
	{
		return (0);
	}
	va_start(args, format);
	tokens = ft_tokenizer((char *)format, &args);
	va_end(args);
	if (tokens == NULL)
		return (-1);
	result = ft_lstprint(tokens);
	free_list(&tokens);
	return (result);
}

// int main(void)
// {
//    int	printf_result;
//    int	ftprintf_result;

// 	printf("*********Teste***********\nPrintf:\n");
// 	printf_result = printf("This %p is even stranger", (void *)-1);
// 	printf("\nft_printf:\n");
// 	ftprintf_result = ft_printf("This %p is even stranger", (void *)-1);
// 	printf("\nLen Printf: %d, Len ft_print: %d\n", 
//printf_result, ftprintf_result);
// }

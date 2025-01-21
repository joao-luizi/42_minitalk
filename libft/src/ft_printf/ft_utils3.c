/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:15:36 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/01 15:15:36 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/**
 * @brief Verifies if a format information 
 * node has the correct format.
 *
 * This function checks if the given string 
 * representing a format information node
 * has the correct format based on the rules 
 * specified. It iterates through the characters
 * of the string and checks if each character is
 *  a valid specifier or flag.
 *
 * @param content The string representing the 
 * format information node.
 * @return int Returns TRUE (1) if the format is
 *  valid, FALSE (0) otherwise.
 */
static int	valid_template_format(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (!ft_ischarinlist("0123456789*.# -+0cspdiuxX%", content[i]))
			return (FALSE);
		i++;
	}
	if (ft_ischarinlist("cspdiuxX%", content[i - 1]))
		return (TRUE);
	else
		return (FALSE);
}

/**
 * @brief Returns the specifier value based on
 *  the character following '%'.
 *
 * This function returns the specifier value 
 * based on the character following '%'.
 * It maps the character to the corresponding 
 * specifier value defined in the enumeration.
 *
 * @param chr The character following '%'.
 * @return int The specifier value corresponding
 *  to the character.
 */
static int	get_specifier_follow(char chr)
{
	if (chr == '%')
		return (pc);
	else if (chr == 'c')
		return (c);
	else if (chr == 's')
		return (s);
	else if (chr == 'p')
		return (p);
	else if (chr == 'd')
		return (d);
	else if (chr == 'i')
		return (i);
	else if (chr == 'u')
		return (u);
	else if (chr == 'x')
		return (x);
	else if (chr == 'X')
		return (X);
	else
		return (NONE);
}

/**
 * @brief Determines the specifier based on the
 *  content of a format node.
 *
 * This function determines the specifier based
 *  on the content of a format node.
 * It checks various conditions to identify the
 *  specifier and returns the appropriate value.
 *
 * @param content The content of the format node.
 * @return int The specifier value determined 
 * based on the content.
 */
static int	get_specifier(char *content)
{
	int	len;

	if (!content)
		return (NONE);
	len = ft_strlen(content);
	if (content[0] == '%' && (len == 1 || ft_strlenif(content, " #+-.*") == 1))
		return (ERROR);
	if (content[0] == '%' && content[len - 1] == '%')
		return (pc);
	if (content[0] == '%' && valid_template_format(content))
		return (get_specifier_follow(content[len - 1]));
	else
		return (NONE);
}

/**
 * @brief Creates a new node in the form of a
 *  t_info_list struct.
 *
 * This function creates a new node in the form
 *  of a t_info_list struct and populates it
 * with the provided content and format 
 * information obtained from the format string and
 * arguments list. It allocates memory for 
 * the node and the associated t_info struct.
 *
 * @param content The format string for the 
 * node.
 * @param args The va_list arguments list for 
 * format specification.
 * @return t_info_list* A pointer to the newly 
 * created node, or NULL if memory allocation fails.
 */
t_info_list	*get_new_lst(char *content, va_list *args)
{
	t_info_list	*new;
	t_info		*info;

	new = malloc(sizeof(t_info_list));
	if (!new)
		return (NULL);
	info = malloc(sizeof(t_info));
	if (!info)
	{
		free(new);
		return (NULL);
	}
	info->specifier = get_specifier(content);
	format_info(info, content, args);
	new->info = info;
	new->content = get_formatted_string(info, content, args);
	new->next = NULL;
	return (new);
}

/**
 * @brief Constructs the final string considering
 *  the minimum width and maximum characters.
 *
 * This function allocates memory for a new string
 *  and fills it based on the 
 * provided source string, minimum width, maximum
 *  characters to include, and 
 * formatting information specified in the t_info
 *  structure.
 *
 * @param src The source string to be formatted.
 * @param min_width The minimum width of the resulting
 *  string.
 * @param max_char The maximum number of characters to
 *  include from the source string.
 * @param info Pointer to a structure containing 
 * formatting information, such as padding and flags.
 *
 * @return A pointer to the newly allocated and 
 * formatted string, or NULL if memory allocation fails.
 */
char	*final_string(char *src, size_t min_width,
			size_t max_char, t_info *info)
{
	size_t	i;
	char	*result;
	int		offset;

	offset = 0;
	result = malloc(sizeof(char) * (min_width + 1));
	if (result == NULL)
		return (NULL);
	result[min_width] = '\0';
	ft_memset(result, info->padding, min_width);
	if (info->flags >= 0 && !(info->flags & MINUS))
		offset = min_width - max_char;
	i = 0;
	while (i < min_width)
	{
		if (src[i] && max_char > 0)
		{
			result[i + offset] = src[i];
			max_char--;
		}
		else
			break ;
		i++;
	}
	return (result);
}

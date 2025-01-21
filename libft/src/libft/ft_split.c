/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:48:30 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:27 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Frees memory allocated for a list of strings.
 *
 * This function deallocates memory for each
 * string in the given list of strings 'list'
 * and then frees the memory allocated for
 * the list itself. The 'list' parameter is expected
 * to be an array of pointers to dynamically
 * allocated strings, terminated by a NULL pointer.
 *
 * @param list A pointer to the list of
 * strings to be freed. It should be terminated by a NULL pointer.
 */
static void	ft_free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char	*get_pointer(char *s, char sep)
{
	char	*p;

	p = ft_strchr(s, sep);
	if (p == NULL)
		p = ft_strchr(s, '\0');
	return (p);
}

/**
 * @brief Counts the number of words in
 * a string separated by a specified character.
 *
 * This function counts the number of words
 * in the string 's' delimited by the separator character 'c'.
 * Words are sequences of characters separated
 * by instances of 'c'. The count includes the words themselves
 * and does not include consecutive instances
 * of 'c'. If 's' starts with a non-separator character, it is
 * considered as the beginning of the first
 * word.
 *
 * @param s The string in which words are counted.
 * @param c The separator character used to delimit words.
 * @return The number of words in the string 's'.
 */
static int	count_words(const char *s, char sep, int loop)
{
	char	*p;
	int		cursor;

	if (!(*s))
		return (loop);
	p = get_pointer((char *)s, sep);
	cursor = (int)(p - s);
	if (cursor > 0)
	{
		return (count_words((s + cursor), sep, loop + 1));
	}
	else
		return (count_words((s + 1), sep, loop));
}

/**
 * @brief Splits a string into an array of
 *  strings based on a specified separator character.
 *
 * This function splits the string 's' into
 * an array of strings where each element of the array
 * represents a word delimited by the separator
 * character 'c'. The resulting array of strings is
 * stored in the 'string_list' parameter. Each
 * word is dynamically allocated using ft_substr function.
 * If memory allocation fails for any word, the
 * function frees the previously allocated memory and
 * returns NULL. The last element of the 'string_list'
 *  array is set to NULL to indicate the end of
 * the list.
 *
 * @param s The string to be split into words.
 * @param c The separator character used to delimit
 *  words.
 * @param string_list An array of strings where the
 * split words will be stored. It should be large
 *                    enough to hold all the words
 * plus an additional NULL pointer at the end.
 * @return A pointer to the array of strings containing
 *  the split words, terminated by a NULL pointer.
 *         Returns NULL if memory allocation fails for
 * any word.
 */
static char	**ft_inner_split(const char *s, char sep, char **list, int loop)
{
	char	*p;
	int		cursor;

	if (!(*s))
	{
		list[loop] = NULL;
		return (list);
	}
	p = get_pointer((char *)s, sep);
	cursor = (int)(p - s);
	if (cursor > 0)
	{
		list[loop] = ft_substr(s, 0, cursor);
		if (list[loop] == NULL)
		{
			ft_free_list(list);
			return (list);
		}
		list = ft_inner_split((s + cursor), sep, list, loop + 1);
	}
	else
		list = ft_inner_split((s + 1), sep, list, loop);
	return (list);
}

/**
 * \brief Splits a string into substrings
 based on a delimiter character.
 *
 * This function splits the input string `s`
 into substrings using the delimiter character `c`.
 * It returns an array of strings (`char**`),
	where each element of the array contains
	a substring. Calls `libft.a` functions `ft_substr()`
 *
 * \param s A pointer to the input string to
 be split.
 * \param c The delimiter character used to
 separate substrings.
 *
 * \return A pointer to an array of strings
 (`char**`) containing the extracted substrings.
 */
char	**ft_split(const char *s, char c)
{
	char	**string_list;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = count_words(s, c, 0);
	string_list = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (string_list == NULL)
		return (NULL);
	string_list = ft_inner_split(s, c, string_list, 0);
	return (string_list);
}

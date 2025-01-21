/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 15:37:33 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/**

	* Calculates the total length required for 
	concatenating command line arguments.
 *
 * This function computes the total length needed to store all strings in `argv`
 * when concatenated with the specified `separator` character.
 *
 * @param argv The array of strings (command line arguments).
 * @param separator The character to be used as a separator.
 *
 * @return The total length required for the concatenated string.
 */
static size_t	calculate_total_length(char **argv, char separator)
{
	size_t	i;
	size_t	total_len;

	total_len = 0;
	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 0)
		{
			total_len += ft_strlen(argv[i]);
			if (separator && argv[i + 1])
				total_len++;
		}
		i++;
	}
	return (total_len);
}

/**
 * Populates a string with concatenated command line arguments.
 *
 * This function fills the provided pointer with the concatenated strings from
 * the `argv` array, using the specified `separator` character where needed.
 *
* @param ptr Pointer to the destination where 
	the concatenated string will be stored.
 * @param argv The array of strings (command line arguments).
 * @param separator The character to be used as a separator.
 */
static void	populate_concatenated_string(char **ptr, char **argv,
		char separator)
{
	int		i;
	int		add_separator;
	char	*s;

	i = 0;
	add_separator = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 0)
		{
			if (add_separator && separator)
				*(*ptr)++ = separator;
			s = argv[i];
			while (*s)
				*(*ptr)++ = *s++;
			add_separator = 1;
		}
		i++;
	}
}

/**
 * Joins strings from the specified index in argv with a separator character.
 *
 * This function concatenates strings in argv starting from the specified
 * index into a single string, with each string separated by the given
 * separator character. If the start index is invalid, it defaults to
 * joining from the beginning.
 *
 * @param start_index The index from which to start joining strings.
 *                    If invalid, defaults to 0.
 * @param argv The array of strings to join.
 * @param separator The character to use as a separator between strings.
 *
 * @return A newly allocated string containing the joined strings, or
 *         NULL if memory allocation fails.
 */
char	*join_strings_with_separator(int start_index, char **argv,
		char separator)
{
	size_t	total_len;
	char	*final;
	char	*ptr;
	int		argv_len;

	argv_len = 0;
	while (argv[argv_len])
		argv_len++;
	if (start_index < 0 || start_index >= argv_len)
		start_index = 0;
	total_len = calculate_total_length(argv + start_index, separator);
	final = malloc(total_len + 1);
	if (!final)
		return (NULL);
	ptr = final;
	populate_concatenated_string(&ptr, argv + start_index, separator);
	*ptr = '\0';
	return (final);
}

/**
 * Frees an array of strings.
 *
 * This function iterates through the array of strings and frees each allocated
 * string, followed by freeing the array itself.
 *
 * @param str The array of strings to be freed.
 */
void	free_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

	/**
		* Parses command line arguments into 
		a normalized format.
		*
		* This function concatenates the command 
		line arguments with the specified
		* separator and splits them into an array of strings for easier parsing.
		*
		* @param argv The array of command line arguments.
		* @param separator The character to be used as a separator.
		*
		* @return An array of strings representing the
		 normalized arguments,
		*         or NULL if memory allocation fails.
	*/
char **
	parse_command_line_arguments(int *argc, char **argv, char separator)
{
	char	**normal_argv;
	char	*single_arg;

	if (!separator)
		separator = '\0';
	single_arg = join_strings_with_separator(0, argv, separator);
	if (!single_arg)
		return (NULL);
	normal_argv = ft_split(single_arg, separator);
	if (!normal_argv)
	{
		free(single_arg);
		return (NULL);
	}
	free(single_arg);
	if (argc)
	{
		*argc = 0;
		while (normal_argv[*argc])
			(*argc)++;
	}
	return (normal_argv);
}

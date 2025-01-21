/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:47:08 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:52:02 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

/**
 * @brief Copies the contents of a buffer to a
 * destination until a newline or buffer size limit is reached.
 *
 * This function copies characters from the source
 *  buffer `bf` to the destination `dst`
 * until either a newline character (`'\n'`) is
 * encountered or the defined `BUFFER_SIZE`
 * limit is reached. The copying stops at the first
 * newline character found.
 *
 * @param dst The destination buffer where the
 * contents are to be copied.
 * @param bf The source buffer from which the
 * contents are to be copied.
 *
 * @note The destination buffer should be large
 * enough to hold the copied contents.
 * @note The function assumes that `BUFFER_SIZE`
 *  is properly defined elsewhere in the code.
 */
void	copy_buffer(char *dst, char *bf)
{
	size_t	x;

	x = 0;
	while (bf[x] && (int)x < BUFFER_SIZE)
	{
		dst[x] = bf[x];
		if (dst[x] == '\n')
			break ;
		x++;
	}
}

/**
 * @brief Joins the content of the buffer
 * with the current line.
 *
 * This function concatenates the contents
 *  of the source buffer `bf` with the
 * current line stored in `original`. It
 *  allocates a new buffer large enough
 * to hold both the original string and the
 *  buffer content, copies the original
 * string and the buffer content into the
 *  new buffer, and returns the resulting
 * string. The function handles memory
 * allocation and ensures the original
 * string is freed if necessary.
 *
 * @param original The current line that
 *  has been read so far.
 * @param bf The buffer containing new
 * content to be appended to the current line.
 * @return A dynamically allocated string
 *  containing the concatenated result, or
 *         NULL if memory allocation fails.
 *  The caller is responsible for freeing
 *         the returned string.
 *
 * @note This function uses `custom_strlen`
 *  to determine the lengths of the
 *       original string and the buffer. It
 * also uses `copy_buffer` to perform
 *       the copying and `reset_buffer` to
 *  reset the buffer after copying.
 */
char	*join_strings(char *original, char *bf)
{
	char	*result_too;
	size_t	cnt_result;
	size_t	cnt_buffer;
	size_t	x;

	cnt_result = custom_strlen(original);
	cnt_buffer = custom_strlen(bf);
	x = 0;
	result_too = malloc(sizeof(char) * (cnt_buffer + cnt_result + 1));
	if (result_too == NULL)
		return (NULL);
	while (original && original[x])
	{
		result_too[x] = original[x];
		x++;
	}
	copy_buffer(&result_too[x], bf);
	result_too[cnt_buffer + cnt_result] = '\0';
	if (original)
		free(original);
	reset_buffer(bf);
	return (result_too);
}

/**
 * @brief Calculates the length of a string
 * up to the end or the first newline character.
 *
 * This function returns the length of the given
 *  string `s` up to the first newline character (`'\n'`)
 * or the null terminator (`'\0'`). If a newline
 *  character is encountered, it is included in the
 * returned length.
 *
 * @param s The input string whose length is to
 *  be calculated.
 * @return The length of the string up to and
 * including the first newline character, or the null
 *         terminator if no newline is present.
 *  Returns 0 if the input string is NULL.
 */
size_t	custom_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

/**
 * @brief Resets the buffer by shifting
 * contents after a newline character.
 *
 * This function processes the buffer `bf`
 *  to reset its contents. It searches for
 *  the first
 * newline character (`'\n'`). If found, it
 *  removes everything up to and including that
 *  newline, shifting the remaining contents to
 *  the beginning of the buffer and filling the rest with
 * null characters (`'\0'`). This effectively
 * prepares the buffer for the next read operation.
 *
 * @param bf The buffer to be reset. The buffer
 *  is assumed to have a size defined by `BUFFER_SIZE`.
 *
 * @note The function assumes that `BUFFER_SIZE`
 *  is properly defined elsewhere in the code.
 * @note If no newline character is found, the
 * buffer is completely filled with null characters.
 */
void	reset_buffer(char *bf)
{
	size_t	i;
	size_t	j;
	int		nl_found;

	nl_found = FALSE;
	i = 0;
	j = 0;
	while ((int)i < BUFFER_SIZE)
	{
		if (bf[i] == '\n' && !nl_found)
		{
			nl_found = TRUE;
			bf[i] = '\0';
			i++;
		}
		if (nl_found)
		{
			bf[j] = bf[i];
			j++;
		}
		bf[i] = '\0';
		i++;
	}
}

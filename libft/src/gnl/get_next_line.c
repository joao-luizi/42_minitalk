/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:54:45 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:51:59 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

/**
 * @brief Reads a line from a specified
 *  file descriptor, supporting multiple file descriptors.
 *
 * This function reads from the given
 * file descriptor (or standard input) line by line,
 * considering the end of a line to be
 * either the newline character (`\n`) or the null
 * terminator (`\0`). It supports reading from
 *  multiple file descriptors by using a
 * static buffer array indexed by file descriptor.
 *
 * @param fd The file descriptor to read from.
 * This can be a file or standard input.
 * @return A dynamically allocated string containing
 *  the next line read from the file
 *         descriptor, or NULL if an error occurs or
 *  if there are no more lines to read.
 *         The caller is responsible for freeing
 *  the returned string.
 *
 * @note This function does not handle binary files
 *  and assumes the input is text.
 * @note The function uses a static buffer indexed
 *  by file descriptor, which limits the
 *       number of simultaneous file descriptors
 *  it can handle to `FOPEN_MAX`.
 * @note If the `BUFFER_SIZE` is set to 0 or less,
 *  the function will return NULL.
 */
char	*get_next_line(int fd)
{
	char		*result;
	int			i;
	static char	bf[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd > FOPEN_MAX || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	result = NULL;
	while (bf[fd][0] || read(fd, bf[fd], BUFFER_SIZE) > 0)
	{
		result = join_strings(result, bf[fd]);
		if (result == NULL)
			return (NULL);
		i = 0;
		while (result && result[i])
		{
			if (result[i] == '\n')
				return (result);
			i++;
		}
	}
	return (result);
}
// int main(void)
// {
//     int		fd;
// 	int		fd2;
//     char	*newline;
// 	char	*newline2;

//     // fd = open("./examples/1char.txt", O_RDONLY);
//     // fd = open("./examples/empty.txt", O_RDONLY);
//     //fd = open("./examples/giant_line_nl.txt", O_RDONLY);
//      //fd = open("./examples/giant_line.txt", O_RDONLY);
//     // fd = open("./examples/lines_around_10.txt", O_RDONLY);
//     // fd = open("./examples/multiple_nl.txt", O_RDONLY);
//     // fd = open("./examples/mytest.txt", O_RDONLY);
//     // fd = open("./examples/one_line_no_nl.txt", O_RDONLY);
//     // fd = open("./examples/only_nl.txt", O_RDONLY);
//      fd = open("./examples/read_error.txt", O_RDONLY);
// 	//fd = open("./examples/variable_nls.txt", O_RDONLY);
// 	fd2 = open("./examples/variable_nls.txt", O_RDONLY);
//     while (1)
//     {
//         newline = get_next_line(fd);
//         if (newline == NULL)
// 		{
// 			close(fd);
// 			fd = - 1;
// 		}
// 		else
// 		{
//         	printf("---------------->%s", newline);
// 			free(newline);
// 		}

// 		newline2 = get_next_line(fd2);
//         if (newline2 == NULL)
// 		{
//             close(fd2);
// 			fd2 = - 1;
// 		}
// 		else
// 		{
//         	printf("---------------->%s", newline2);
// 			free(newline2);
// 		}
// 		if (fd < 0 && fd2 < 0)
// 			break ;
//     }
//     return (0);
// }
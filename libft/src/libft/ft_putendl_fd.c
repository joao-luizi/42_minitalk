/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:34:16 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:20 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Writes a string followed
 by a newline character to a file descriptor.
 *
 * \param s The string to write.
 * \param fd The file descriptor to
 which the string will be written.
 * \return None
 *
 * \remark function writes the string
 \p s to the file descriptor \p fd,
	followed by a newline character.

	* It uses the `write` system call
	to perform the writing operation.
	The length of the string is determined
 * using the ft_strlen function. After
 writing the string,
	it writes a newline character '\n'
	to the file
 * descriptor. No return value is
 provided,
	as the function only performs write
	operations and does not return
 * any meaningful result.
 */
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

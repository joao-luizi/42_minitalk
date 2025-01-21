/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:35:16 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:17 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Writes a character to
 a file descriptor.
 *
 * \param c The character to write.
 * \param fd The file descriptor
 to which the character will be written.
 * \return None
 *
	* \remark function writes the character
	\p c to the file descriptor \p fd.
	It uses the `write` system call
 * to perform the writing operation.
 If successful,
	the character is written to the
	file descriptor.
 * No return value is provided,
	as the function only performs a write
	operation and does not return any
 * meaningful result.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

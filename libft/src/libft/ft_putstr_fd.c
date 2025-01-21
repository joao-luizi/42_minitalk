/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:53:48 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:24 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * \brief Writes a string to a file descriptor.
 *
 * \param s The string to write.
 * \param fd The file descriptor to which the
 string will be written.
 * \return None
 *
 * \remark function writes the string \p s to
 the file descriptor \p fd. It uses the `write` system call
 * to perform the writing operation. The length
 of the string is determined using the ft_strlen function.
 * If successful,
	the entire string is written to the file descriptor.
	No return value is provided,
 * as the function only performs a write operation and
 does not return any meaningful result.
 */
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

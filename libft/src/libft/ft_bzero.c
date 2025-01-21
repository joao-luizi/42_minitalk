/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:20:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:23 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Zeroes out a block of memory.
 *
 * This function sets the first 'n' bytes of the memory
 area pointed to by 'dest' to zero.
 * Calls `libft.a` function `ft_memset()`
 *
 * @param dest Pointer to the memory area to be zeroed out.
 * @param n Number of bytes to be set to zero.
 *
 */
void	ft_bzero(void *dest, size_t n)
{
	ft_memset(dest, '\0', n);
}

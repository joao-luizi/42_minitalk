/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:46:01 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:58 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Applies a function to each character
 * of a string with its index.
 *
 * This function iterates over each character
 * of the string 's' and applies the function 'f'
 * to each character along with its corresponding
 *  index. The function 'f' takes two parameters:
 * the index of the character and a pointer to
 * the character itself. The index starts from 0 for
 * the first character of the string.
 *
 * @param s The string whose characters will
 *  be processed.
 * @param f A pointer to the function to apply
 * to each character. The function should have the
 *          following signature:
 * void f(unsigned int index, char *character).
 *          - index: The index of the character
 *  being processed.
 *          - character: A pointer to the
 *  character being processed.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		f((unsigned int)i, (s + i));
		i++;
	}
}

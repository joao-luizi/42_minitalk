/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:39:02 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:12 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**

 * \brief Applies a function to each character
 of a string and creates a new string from the results.
 Calls `libft.a` function `ft_strlen()`.
 *
 * \param s The input string on which to apply the
 function.
 * \param f The function to apply to each character,
	taking the index of the character and the
	character itself as arguments.
* \return Pointer to the newly created string containing
the results of applying the function.
 *
 * \remark function applies the function \p f to
 each character of the input string \p s,
	passing the index

 * of the character and the character itself as arguments.
 The results of applying \p f are collected
 * in a newly allocated string,
	which is returned to the caller. Memory is dynamically
	allocated for
* the new string using malloc. If memory allocation fails
during string creation,
	the function returns
 * NULL to indicate an error.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(p + i) = f((unsigned int)i, *(s + i));
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

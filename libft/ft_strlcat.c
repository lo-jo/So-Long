/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:36:55 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/18 11:27:02 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i + ft_strlen(&src[j]));
}

/*
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate
 strings respectively.  They are designed to be safer, more con
‐sistent, and less error prone replacements for strncpy(3)
and strncat(3).  Unlike those functions, strlcpy() and strlcat(
) take the full size of the buffer (not just the length) and
 guarantee to NUL-terminate the result (as long as size is larg
er than 0 or, in the case of strlcat(), as long as there is at
least one byte free in dst).  Note that a byte for the NUL
should be included in size.  Also note that strlcpy() and
strlcat() only operate on true “C” strings.  This means that for
 strlcpy() src must be NUL-terminated and for strlcat() bot
h src and dst must be NUL-terminated.

 RETURN VALUES
     The strlcpy() and strlcat() functions return the total length
      of the string they tried to create.
      For strlcat() that means the initial length of dst plus the length
	  of src.
    While this may seem somewhat
     confusing, it was done to make truncation detection simple.

     Note, however, that if strlcat() traverses size characters without
	 finding a NUL,
      the length of the string is considered to
     be size and the destination string will not be NUL-terminated
     (since there was no space for the NUL).  This keeps strlcat()
     from running off the end of a string.  In practice this should not happen
     (as it means that either size is incorrect or that
     dst is not a proper “C” string).
     The check exists to prevent potential security problems in incorrect code.
*/

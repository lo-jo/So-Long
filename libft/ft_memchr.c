/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:48:29 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/18 11:00:20 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
DESCRIPTION
       The  memchr()  function scans the initial n bytes of the
	    memory area pointed to by s for the first instance of c.
		Both c and the bytes of the memory
       area pointed to by s are interpreted as unsigned char.
RETURN VALUE
       The memchr() and memrchr() functions return a pointer to
	   the matching byte or NULL if the character does not occur
	   in the given memory area.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:13:25 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/18 11:06:11 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (0);
	while (i < n)
	{
	((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	i++;
	}
	return (dest);
}

/*
DESCRIPTION
       The  memcpy()  function copies n bytes from memory
	   area src to memory area dest.  The memory areas must not
       overlap.  Use memmove(3) if the memory areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:50:14 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/18 13:31:58 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n--)
		{
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else if (src > dest)
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

/*
DESCRIPTION
       The  memmove() function copies n bytes from memory area
	   src to memory area dest.  The memory areas may overlap:
	   copying takes place as
       though the bytes in src are first copied into a temporary array
	   that does not overlap src or dest, and the bytes are then copied
	   from
       the temporary array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.
*/

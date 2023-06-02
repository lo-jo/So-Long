/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:30:45 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/18 16:45:53 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb >= 2147483647 || size >= 2147483647)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size * nmemb);
	return (buffer);
}
/*
DESCRIPTION
       The  calloc()  function allocates memory for an array of nmemb
	   elements of size bytes each and returns a pointer to the allocated
	   memory.
	   The memory is set to zero.  If nmemb or size is 0, then calloc()
	   returns either NULL,
	   or a unique pointer value that can later be successfully passed
	   to free().
       If the multiplication of nmemb and size would result in integer
	   overflow, then calloc()
	   returns an error.  By contrast, an integer overflow would not
       be detected in the following call to malloc(), with the result
	   that an incorrectly
	   sized block of memory would be allocated:

           malloc(nmemb * size);
RETURN VALUE
       The malloc() and calloc() functions return a pointer to the
	   allocated memory, which is
	   suitably aligned for any built-in type.  On error, these func‐
       tions return NULL.  NULL may also be returned by a successful
	   call to malloc() with a
	   size of zero, or by a successful call to calloc() with nmemb or
       size equal to zero.

       The free() function returns no value.
*/

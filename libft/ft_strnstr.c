/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:25:55 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/17 12:33:26 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the 
	 null-terminated string little in the string big, where not 
	 more than len characters are searched.  Characters that appear
	  after a ‘\0’ character are not searched.  Since the strnstr() 
	  function is a FreeBSD specific API, it should only be used
     when portability is not a concern.
RETURN VALUES
     If little is an empty string, big is returned; if little occurs 
	 nowhere in big, NULL is returned; otherwise a pointer to the 
	 first character of the first
     occurrence of little is returned.
*/
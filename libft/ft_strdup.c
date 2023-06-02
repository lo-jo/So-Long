/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:49:34 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/17 12:35:07 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		size;
	int		i;

	size = ft_strlen(s) + 1;
	dup = (char *)malloc(size * sizeof(char));
	if (dup == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
DESCRIPTION
       The  strdup() function returns a pointer to a 
	   new string which is a duplicate of the string s.
       Memory for the new string is obtained with malloc(3),
	    and can be freed with free(3).

RETURN VALUE
       On success, the strdup() function returns a pointer to 
	   the duplicated string.  It returns NULL
       if insufficient memory was available, with errno set to 
	   indicate the cause of the error.
*/

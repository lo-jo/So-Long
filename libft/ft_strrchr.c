/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:08:40 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/19 13:46:50 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/*
DESCRIPTION
The strrchr() function returns a pointer to the last occurrence
of the character c in the string s.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the
	   matched character or NULL if the character is not found.
	   The terminating null  byte  is considered part of the string,
	   so that if c is specified as '\0', these functions return a 
	   pointer to the terminator.
*/

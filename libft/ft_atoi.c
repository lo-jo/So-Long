/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:15:54 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/16 16:21:50 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r'))
	i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] && (ft_isdigit(nptr[i])))
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nbr);
}
/*
DESCRIPTION
       The atoi() function converts the initial portion of the string pointed
	   to by nptr to int.
	   The behavior is the same as
           strtol(nptr, NULL, 10);
       except that atoi() does not detect errors.
RETURN VALUE
       The converted value.

DESCRIPTION
       The strtol() function converts the initial part of the string in nptr
	   to a long integer value
	   according to the given base, which must be between 2 and 36 inclusive, or be
       the special value 0.

       The string may begin with an arbitrary amount of white space 
	   (as determined by isspace(3)) followed
	   by a single optional '+' or '-' sign.  
*/

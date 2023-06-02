/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:25:27 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/19 13:50:04 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count ++;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nbr;
	int		i;

	i = nbrlen(n);
	nbr = n;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (nbr < 0)
	{
	s[0] = '-';
	nbr *= -1;
	}
	if (nbr == 0)
		s[0] = '0';
	while (nbr > 0)
	{
		s[i] = nbr % 10 + '0';
		nbr /= 10;
		i --;
	}
	return (s);
}
/*
DESCRIPTION
Alloue (avec malloc(3)) et retourne une chaîne
de caractères représentant l’entier ’n’ reçu en
argument. Les nombres négatifs doivent être gérés.
RETURN VALUE
La chaîne de caractères représentant l’entier.
NULL si l’allocation échoue.
*/

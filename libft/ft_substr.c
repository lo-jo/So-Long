/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:53:36 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/23 15:38:18 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	finish;
	char			*sub;
	unsigned int	maxlen;

	if (!s)
		return (NULL);
	maxlen = ft_strlen(s);
	finish = 0;
	if (start <= maxlen)
		finish = maxlen - start;
	if (start >= maxlen)
		return (ft_strdup(""));
	if (finish >= len)
		finish = len;
	sub = (char *)malloc(sizeof(char) * (finish + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, finish + 1);
	return (sub);
}

/*
Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’.

RETURN VALUE
La nouvelle chaîne de caractères.
NULL si l’allocation échoue
*/

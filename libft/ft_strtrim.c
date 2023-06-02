/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:07 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/21 13:58:44 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			maxlen;
	char			*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	maxlen = ft_strlen(s1);
	while (maxlen && ft_strchr(set, s1[maxlen]))
		maxlen--;
	new = ft_substr((char *)s1, start, maxlen + 1);
	return (new);
}

/*
DESCRIPTION
Alloue (avec malloc(3)) et retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaîne de
caractères.
RETURN VALUE
La chaîne de caractères trimmée.
NULL si l’allocation échoue
*/

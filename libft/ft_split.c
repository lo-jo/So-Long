/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:47:52 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/24 11:55:03 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	len;

	len = 0;
	if ((*s != c) && *s)
	{
		len++;
		s++;
	}
	while (*s)
	{
		if ((*s != c) && s[-1] == c)
			len++;
		s++;
	}
	return (len);
}

static int	wordsize(int i, char const *s, char c)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] != c)
			size++;
		i++;
	}
	return (size);
}

static	void	splitter(char const *s, char c, char **split)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			k = 0;
			split[j] = malloc(sizeof(char) * wordsize(i, s, c) + 1);
			while (s[i] && (s[i] != c))
			{
				split[j][k] = s[i];
				i++;
				k++;
			}
			split[j][k] = '\0';
			j++;
		}
		if (s[i])
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**split;

	if (!s)
		return (NULL);
	size = wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	splitter(s, c, split);
	split[size] = NULL;
	return (split);
}

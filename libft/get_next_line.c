/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:04:25 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/26 14:00:50 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*build_line(char *static_stock)
{
	int		i;
	char	*str;

	i = 0;
	if (!static_stock[i])
		return (NULL);
	while (static_stock[i] && static_stock[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (static_stock[i] && static_stock[i] != '\n')
	{
		str[i] = static_stock[i];
		i++;
	}
	if (static_stock[i] == '\n')
	{
		str[i] = static_stock[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*nextline(char *static_stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (static_stock[i] && static_stock[i] != '\n')
		i++;
	if (!static_stock[i])
	{
		free(static_stock);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(static_stock) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (static_stock[i])
		str[j++] = static_stock[i++];
	str[j] = '\0';
	free(static_stock);
	return (str);
}

char	*read_line(int fd, char *static_stock)
{
	char	*buf;
	int		count;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	count = 1;
	while (!ft_strchr(static_stock, '\n') && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[count] = '\0';
		static_stock = ft_strjoin(static_stock, buf);
	}
	free(buf);
	return (static_stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_stock = read_line(fd, static_stock);
	if (!static_stock)
		return (NULL);
	line = build_line(static_stock);
	static_stock = nextline(static_stock);
	return (line);
}
/*
1. READ AND SAVE : read from fd until \n or \0 is encountered
> loop until read returns 0 which means we have reached EOF and
 there is nothing left to read
	Read the file sent through fd
	If read returns -1 an error has occured >> free and return 0
	Store the characters read into a static variable
	(join buffer and static)
	Check if there is a \n inside the static, if yes, stop. if not, keep looping

2. BUILD LINE ; this function is called when we have encountered a \n or EOF
	> extracts characters until \n to build the string to be returned
--- counts characters until \n
--- malloc string of the size +2
--- copy characters
--- return string

3. NEXTLINE : Store the characters that dont need to be read
> reajust the static variable by storing all the unecessary characters
 read after \n
If this function is called, that means that we have reached the EOF
 or there is a \n
> characters are extracted until \n in order to get the line to return
--- count the characters until the \n
--- malloc string with the length
--- copy until \n and add the final \0
--- return new chain
*/

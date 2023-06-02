/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:01:27 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/31 11:14:04 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char *map_name)
{
	int		fd;
	char	*map_tmp;
	char	*line_tmp;
	char	*buffer;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit_error("Oops ! Failed to open your map.", 1, game);
	map_tmp = ft_strdup("");
	game->mapline = 0;
	while (1)
	{
		line_tmp = get_next_line(fd);
		if (!line_tmp)
			break ;
		if (line_tmp == NULL || line_tmp[0] == '\n')
			write_error("Your map has an empty line\n", 1);
		buffer = map_tmp;
		map_tmp = ft_strjoin(buffer, line_tmp);
		free(line_tmp);
		game->mapline++;
	}
	close(fd);
	game->map = ft_split(map_tmp, '\n');
	free(map_tmp);
}

void	read_map(t_game *game, char *map_name)
{
	init_map(game, map_name);
	if (!game->map[0])
		exit_error("Your map could not be initialised. \
Perhaps you submitted a directory ;)\n", 1, game);
	game->mapcol = ft_strlen(game->map[0]);
	check_map(game);
}
/*
***init map
1. The function will call get next line to read the .ber map
Gnl is called until the end of file is met
All lines read will be stored into one big line created with strjoin
for later use.
At the same time, all /n encountered at the beginning of any line
will be discarded because it means there's an empty line in the map
All line read will be counted and stored in game->mapline which will be
the height of our map
The big line will be passed onto ft_split which will build our 2d char
array map.
** Quick check to discard any .ber that is a .ber but a directory
** if it correct, the width of our map is iniatiated for later use
** check_map will check all map configuration requirements
*/
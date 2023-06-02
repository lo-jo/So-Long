/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:10:16 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/29 12:07:26 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangle(t_game *game)
{
	int	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
			exit_error("Error.\nYour map must be a rectangle.\n", 1, game);
		i++;
	}
}

void	is_valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C' && game->map[i][j] != '1'
				&& game->map[i][j] != '0')
				exit_error("Error.\nOnly PEC10 allowed.\n", 1, game);
			j++;
		}
		i++;
	}
}

void	is_surrounded(t_game *game)
{
	int	line;
	int	col;

	col = -1;
	while (++col < game->mapcol)
	{
		if (game->map[0][col] != '1'
			|| game->map[game->mapline - 1][col] != '1')
			exit_error("Error.\nTHESE WALLS ARE NOT RIGHT!!\n", 1, game);
	}
	line = -1;
	while (++line < game->mapline)
	{
		if (game->map[line][0] != '1'
			|| game->map[line][game->mapcol - 1] != '1')
			exit_error("Error.\nTHESE WALLS ARE NOT RIGHT\n", 1, game);
	}
}

void	is_playable(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
					game->player_l = i;
					game->player_col = j;
					game->pcount++;
			}
			else if (game->map[i][j] == 'E')
				game->ecount++;
			else if (game->map[i][j] == 'C')
				game->ccount++;
			j++;
		}
		i++;
	}
	if (game->pcount != 1 || game->ecount == 0 || game->ccount == 0)
		exit_error("Error.\n Your map must have one single P \
at least one E and C.\n", 1, game);
}

void	check_map(t_game *game)
{
	is_rectangle(game);
	is_valid_char(game);
	is_surrounded(game);
	is_playable(game);
	game->collected = game->ccount;
}

/*
This part checks any configuration error encountered in your map.
**** is rectangle
Will check if map is rectangle by comparing the length of lines
Technically, a square is a rectangle so no need to bother with that.
**** is valid char
Will go trough each char in the map and check is the input is anything
but PEC10
**** is surrounded
Will go through the surrounding chars of the map and check if they are walls
**** is playable
Will go through every char and check if the map has minimum playability
Ie. One P, at least one C and at least one E.

The "collected" var is initiated for later use in the program.

Upon error, the program will send 'Error\n' followd by a custom msg.
If everything went right, program will move onto the init_game function
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:36:00 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/31 12:12:32 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trigger_manhole(t_game *game)
{
	if (game->collected == 0)
	{
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		exit_error("Bzzzzzzzzzzzzzz\n", 0, game);
	}
	else
		ft_putstr_fd("Eat them All !!\n", 2);
}

void	update_map(t_game *game, int line, int col)
{
	game->map[game->player_l][game->player_col] = '0';
	game->map[game->player_l + line][game->player_col + col] = 'P';
	game->player_l = game->player_l + line;
	game->player_col = game->player_col + col;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

void	move(t_game *game, int line, int col)
{
	char	c;

	c = game->map[game->player_l + line][game->player_col + col];
	if (c != '1')
	{
		if (c == '0')
			update_map(game, line, col);
		if (c == 'C')
		{
			game->collected -= 1;
			update_map(game, line, col);
		}
		if (c == 'E')
			trigger_manhole(game);
	}
}

int	press_key(int key, t_game *game)
{
	if (key == ESC)
		trigger_escape(game);
	else if (key == WKEY)
		move(game, -1, 0);
	else if (key == AKEY)
		move(game, 0, -1);
	else if (key == SKEY)
		move (game, 1, 0);
	else if (key == DKEY)
		move (game, 0, 1);
	print_map(game);
	return (0);
}

void	trigger_game(t_game *game)
{
	mlx_key_hook(game->win, press_key, game);
	mlx_hook(game->win, 17, 0, trigger_escape, game);
}

/*
see mlx man pages for mlx keyhook and hook
key hook will define what to do depending on what
key you press on the keyboard
mlk hook is to manage exit when clicking on the window's X
**press_key
defined in the header file are the keys
# define ESC 27 close window
# define W 119 up line -1 col 0
# define A 97 left line 0, col -1
# define S 115 down line 1, col 0
# define D 100 right line 0, col 1
Moves on the map are calculated depending on what key is pressed
each time the map has to be updated with new positions and characters
**trigger manhole
is specific when you reach the exit you have to check if you have 
collected everything before being able to escape

*/
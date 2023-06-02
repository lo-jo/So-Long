/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:20:09 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/31 10:23:50 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_game *game)
{
	int		width;
	int		height;

	game->player = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm",
			&width, &height);
	if (game->player == NULL)
		exit_error("Could not load Player XPM", 1, game);
	game->coll = mlx_xpm_file_to_image(game->mlx, "./sprites/coll.xpm",
			&width, &height);
	if (game->coll == NULL)
		exit_error("Could not load Collectible XPM file", 1, game);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./sprites//exit.xpm",
			&width, &height);
	if (game->exit == NULL)
		exit_error("Could not load Exit XPM file", 1, game);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&width, &height);
	if (game->wall == NULL)
		exit_error("Could not load Wall XPM file", 1, game);
	game->tile = mlx_xpm_file_to_image(game->mlx, "./sprites/tile.xpm",
			&width, &height);
	if (game->tile == NULL)
		exit_error("Could not load Background Tile XPM", 1, game);
}
/*
See man page for explanations
Every sprite init is protected in case theres 
a missing file or something
*/

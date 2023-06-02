/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:44:13 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/29 12:09:55 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Could not initiate mlx ptr", 1, game);
	game->win = mlx_new_window(game->mlx, game->mapcol * IMG_PX,
			game->mapline * IMG_PX, "So Long");
	if (game->win == NULL)
		exit_error("Could not initiate window ptr", 1, game);
	init_sprites(game);
	print_map(game);
	trigger_game(game);
}
/*
All Mlx requirements are set up here
Init sprites will initiate sprites gevtn the map characters
print map will basicall draw it
trigger game will translate keyboard input into the program
game utils 
game->collected initialed in map check_map
game->player_l and game->player_col initialised in map_check
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:21:42 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/31 12:10:25 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprite(t_game *game, int line, int col)
{
	if (game->map[line][col] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->tile,
			col * IMG_PX, line * IMG_PX);
	else if (game->map[line][col] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			col * IMG_PX, line * IMG_PX);
	else if (game->map[line][col] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			col * IMG_PX, line * IMG_PX);
	else if (game->map[line][col] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			col * IMG_PX, line * IMG_PX);
	else if (game->map[line][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coll,
			col * IMG_PX, line * IMG_PX);
}

void	print_map(t_game *game)
{
	int	line;
	int	col;

	game->move_count = ft_itoa(game->moves);
	line = -1;
	while (++line < game->mapline)
	{
		col = -1;
		while (++col < game->mapcol)
		{
			put_sprite(game, line, col);
			mlx_string_put (game->mlx, game->win, 20, 15, 0x0000FF00,
				game->move_count);
		}
	}
	free (game->move_count);
}
/*
Simple loop going through our 2d char array
Will print the matching sprite to the character encountered
see mlx man for mlx put image to window explanations and prototypes
*/
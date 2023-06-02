/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:33:57 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/31 12:02:43 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	trigger_exit(t_game *game)
{
	if (game->coll)
		mlx_destroy_image(game->mlx, game->coll);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->tile)
		mlx_destroy_image(game->mlx, game->tile);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->map)
		free_map(game);
	if (game->win && game->mlx)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
	return (0);
}

int	trigger_escape(t_game *game)
{
	trigger_exit(game);
	ft_putstr_fd("Bzzzzzzzzzzzzzzzz!\n", 1);
	exit (0);
	return (0);
}

void	write_error(char *msg, int errortype)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write (2, &msg[i], 1);
		i++;
	}
	write (2, "\n", 1);
	if (errortype == 1)
		exit (1);
	else
		exit (0);
}

void	exit_error(char *msg, int errortype, t_game *game)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write (2, &msg[i], 1);
		i++;
	}
	write (2, "\n", 1);
	if (errortype == 1)
	{
		trigger_exit(game);
		exit (1);
	}
	else
	{
		trigger_exit(game);
		exit (0);
	}
}
/*
This part handles all error types and messages.
**** Exit error
Was initially the main error function I had set up.
I had to later create non void error functions because of
minilibX requirements.
I kept it because it was convienent to send specific exit types...
Could definitely have done it cleaner but eh
**** Trigger escape
Is specifically designed for when you're pressing Esc or click close.
Because I needed a specific error message for them.
**** Trigger exit
On calling, this function will basically close and free everything.
It is general enough thanks to a series of ifs to be called almost 
anywhere needed.
Tricky because everything had to be in the right order because of 
MinilibX specifics...
**** Free Map
Just frees all memory allocated for the map.
*/
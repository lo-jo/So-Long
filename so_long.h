/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:23:17 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/31 12:09:11 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game{
	void	*mlx;
	void	*win;
	char	**map;
	void	*player;
	void	*coll;
	void	*exit;
	void	*wall;
	void	*tile;
	int		mapcol;
	int		mapline;
	int		moves;
	int		collected;
	int		player_l;
	int		player_col;
	int		pcount;
	int		ecount;
	int		ccount;
	char	*move_count;
}				t_game;

# define ESC 65307
# define WKEY 119
# define AKEY 97
# define SKEY 115
# define DKEY 100
# define IMG_PX 32

// MAIN
void	read_map(t_game *game, char *map_name);
void	init_game(t_game *game);

// READ MAP
void	init_map(t_game *game, char *map_name);
void	extension_check(char *argv);
void	check_map(t_game *game);

// PRINT MAP
void	put_sprite(t_game *game, int line, int col);
void	print_map(t_game *game);

// INIT GAME
void	init_sprites(t_game *game);
void	print_map(t_game *game);
void	trigger_game(t_game *game);

//CHECK MAP
void	is_rectangle(t_game *game);
void	is_valid_char(t_game *game);
void	is_surrounded(t_game *game);
void	is_playable(t_game *game);

//TRIGGER GAME
void	move(t_game *game, int line, int column);
void	update_map(t_game *game, int line, int col);
void	trigger_manhole(t_game *game);
int		press_key(int key, t_game *game);

//EXIT
int		trigger_exit(t_game *game);
int		trigger_escape(t_game *game);
void	free_map(t_game *game);
void	exit_error(char *msg, int errortype, t_game *game);
void	write_error(char *msg, int errortype);

#endif
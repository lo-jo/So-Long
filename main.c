/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:08:11 by ljospin           #+#    #+#             */
/*   Updated: 2022/08/31 11:12:21 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extension_check(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	if ((argv[i - 1] != 'r' && argv[i - 2] != 'e'
			&& argv[i - 3] != 'b' && argv[i - 4] != '.'))
		write_error("Please submit a correct .ber map file", 1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		write_error("Wrong Number Of Parameters.", 1);
	else
	{
		extension_check(argv[1]);
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		if (game == NULL)
			write_error("Memory Allocation Error.", 1);
		read_map(game, argv[1]);
		init_game(game);
		mlx_loop(game->mlx);
	}
	return (0);
}
/*
First arg number check
If arg input is 2, memory is allocated for our struct
**extension check
Will simply check the last characters of the parameter
passed as argument and makes sure it is .ber
Mlx Loop is set at the end so that the game runs properly.
*/
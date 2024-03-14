/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:02:11 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/14 11:54:30 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (validate(&game, argv) != 1)
		{
			ft_close_matrix(game.map.mat);
			return(-1);
		}
		game.mlx = mlx_init();
		game.win
			= mlx_new_window(game.mlx,
				game.map.len * RES, game.map.h * RES, "So_Long");
		init_image(&game);
		print_map(game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_hook(game.win, 17, 1L << 0, ft_quit, &game);
		mlx_loop(game.mlx);
	}
	return (1);
}

int	validate(t_game *g, char **argv)
{
	set_flag(&(g->flag));
	set_game(g, argv[1]);
	if (ft_argcheck(g))
		return (-1);
	dim_matrix(&g->map);
	matrice(&g->map);
	if (check_p_letter(&g->map, &g->flag) != 1)
		return (ft_printf("LO HAI FATTO APPOSTA COGLIONE!"));
	if (check_blood(*g) != 1)
		return (ft_printf("LO HAI FATTO APPOSTA COGLIONE!"));
	return (1);
}

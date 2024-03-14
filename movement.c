/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:57:36 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/12 14:44:20 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//hook wasd e esc

#include "so_long.h"

int	ft_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_hook(int key, t_game *game)
{
	if (key == 65307)
		ft_quit(game);
	else if (key == 119)
		game->nmoves += move_w(game);
	else if (key == 115)
		game->nmoves += move_s(game);
	else if (key == 97)
		game->nmoves += move_a(game);
	else if (key == 100)
		game->nmoves += move_d(game);
	print_map(*game);
	return (0);
}

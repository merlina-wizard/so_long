/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:46:30 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/14 11:53:54 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_game(t_game *game, char *path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.h = 0;
	game->map.path = path;
	game->map.len = 0;
	game->map.mat = NULL;
	game->map.copy = NULL;
	game->nmoves = 0;
	game->loop = 0;
	game->aux_rand = 0;
	return (1);
}

void	set_flag(t_flag *flag)
{
	flag->c = 0;
	flag->e = 0;
	flag->p = 0;
}

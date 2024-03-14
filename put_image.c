/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:06:06 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/12 11:48:04 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_game *g)
{
	int	daje;

	daje = 64;
	g->map.wall.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/wall.xpm", &daje, &daje);
	g->map.bg.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/background.xpm", &daje, &daje);
	g->map.player[0].img
		= mlx_xpm_file_to_image(g->mlx, "xpm/sp.xpm", &daje, &daje);
	g->map.player[1].img
		= mlx_xpm_file_to_image(g->mlx, "xpm/wp.xpm", &daje, &daje);
	g->map.player[2].img
		= mlx_xpm_file_to_image(g->mlx, "xpm/dp.xpm", &daje, &daje);
	g->map.player[3].img
		= mlx_xpm_file_to_image(g->mlx, "xpm/ap.xpm", &daje, &daje);
	g->map.player_to_print.img = g->map.player[0].img;
	g->map.exit.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/exit.xpm", &daje, &daje);
	g->map.coin.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/coin.xpm", &daje, &daje);
	g->map.enemy[0].img
		= mlx_xpm_file_to_image(g->mlx, "xpm/n0.xpm", &daje, &daje);
	g->map.enemy[1].img
		= mlx_xpm_file_to_image(g->mlx, "xpm/n1.xpm", &daje, &daje);
}

void	print_map(t_game g)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	str = ft_itoa(g.nmoves);
	while (x < g.map.len)
	{
		y = 0;
		while (y < g.map.h)
		{
			mlx_put_image_to_window(g.mlx, g.win,
				get_tile(g, g.map.mat[y][x]), x * 64, y * 64);
			y++;
		}
		x++;
	}
	mlx_string_put(g.mlx, g.win, 10, 310, 1, "MOVES:");
	mlx_string_put(g.mlx, g.win, 80, 310, 1, str);
	free(str);
}

void	*get_tile(t_game game, char c)
{
	if (c == '1')
		return (game.map.wall.img);
	if (c == '0')
		return (game.map.bg.img);
	if (c == 'E')
		return (game.map.exit.img);
	if (c == 'P')
		return (game.map.player_to_print.img);
	if (c == 'C')
		return (game.map.coin.img);
	if (c == 'N')
		return (game.map.enemy[0].img);
	else
		return (NULL);
}

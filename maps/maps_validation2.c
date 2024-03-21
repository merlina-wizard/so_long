/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:40:33 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/21 16:12:40 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_mat(t_game g)
{
	char	**copy;
	int		y;

	y = 0;
	copy = (char **)malloc(sizeof(char *) * (g.map.h + 1));
	if (!copy)
		return (NULL);
	copy[g.map.h] = NULL;
	while (y < g.map.h)
	{
		copy[y] = ft_strdup(g.map.mat[y]);
		y++;
	}
	return (copy);
}

void	blood_fill(t_game *g, int y, int x)
{
	g->map.copy[y][x] = '1';
	if (g->map.copy[y + 1][x] != '1' && g->map.copy[y + 1][x] != 'N')
		blood_fill(g, y + 1, x);
	if (g->map.copy[y - 1][x] != '1' && g->map.copy[y - 1][x] != 'N')
		blood_fill(g, y - 1, x);
	if (g->map.copy[y][x + 1] != '1' && g->map.copy[y][x + 1] != 'N')
		blood_fill(g, y, x + 1);
	if (g->map.copy[y][x - 1] != '1' && g->map.copy[y][x - 1] != 'N')
		blood_fill(g, y, x - 1);
}

int	check_blood(t_game g)
{
	int	y;

	y = 0;
	g.map.copy = copy_mat(g);
	blood_fill(&g, g.map.player->posx, g.map.player->posy);
	while (y < g.map.h)
	{
		if (ft_strchr(g.map.copy[y], 'C') != 0)
			return (-1);
		if (ft_strchr(g.map.copy[y], 'E') != 0)
			return (-1);
		y++;
	}
	ft_close_matrix(g.map.copy);
	return (1);
}

int	check_square(t_game g)
{
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(g.map.mat[y]);
	while ((int)ft_strlen(g.map.mat[y]) == len && y < (g.map.h - 1))
			y++;
	if ((int)ft_strlen(g.map.mat[y]) != len)
		return (-1);
	return (1);
}

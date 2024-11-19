/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:01:51 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/19 15:29:47 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_map_surrounded_by_walls(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g->m.width)
	{
		if (g->m.map[0][x] != '1' || g->m.map[g->m.height - 1][x] != '1')
			return (printf("Error\nMap is not surrounded by walls.\n"),
				exit(1), 1);
		x++;
	}
	y = 0;
	while (y < g->m.height)
	{
		if (g->m.map[y][0] != '1' || g->m.map[y][g->m.width - 1] != '1')
			return (printf("Error\nMap is not surrounded by walls.\n"),
				exit(1), 1);
		y++;
	}
	return (0);
}

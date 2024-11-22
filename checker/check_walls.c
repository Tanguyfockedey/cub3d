/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:01:51 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/22 13:16:52 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_borders(t_game *g)
{
	int	x;
	int	y;
	int	len;

	x = -1;
	while (++x < g->m.height)
	{
		len = ft_strlen(g->m.map[x]);
		if (x == 0 || x == g->m.height - 1)
		{
			y = -1;
			while (++y < len)
			{
				if (g->m.map[x][y] != '1' && g->m.map[x][y] != ' '
					&& g->m.map[x][y] != '\t')
					return (printf("Error\nMap is not surrounded by walls.\n"),
						exit(1), 1);
			}
		}
		else if ((g->m.map[x][0] != '1' && g->m.map[x][0] != ' '
				&& g->m.map[x][0] != '\t') || g->m.map[x][len - 1] != '1')
			return (printf("Error\nMap is not surrounded by walls.\n"), exit(1),
				1);
	}
	return (0);
}

static int	check_interior(t_game *g, int x, int y)
{
	if (g->m.map[x][y] == '0' || g->m.map[x][y] == 'N' || g->m.map[x][y] == 'S'
		|| g->m.map[x][y] == 'E' || g->m.map[x][y] == 'W')
	{
		if (g->m.map[x - 1][y] == ' ' || g->m.map[x + 1][y] == ' '
			|| g->m.map[x][y - 1] == ' ' || g->m.map[x][y + 1] == ' '
			|| g->m.map[x - 1][y] == '\0' || g->m.map[x + 1][y] == '\0'
			|| g->m.map[x][y - 1] == '\0' || g->m.map[x][y + 1] == '\0')
			return (printf("Error\nMap is not surrounded by walls.\n"),
				exit(1), 1);
	}
	return (0);
}

int	is_wall(t_game *g)
{
	int	x;
	int	y;
	int	len;

	if (check_borders(g))
		return (1);
	x = 1;
	while (x < g->m.height - 1)
	{
		len = ft_strlen(g->m.map[x]);
		y = 1;
		while (y < len - 1)
		{
			if (check_interior(g, x, y))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

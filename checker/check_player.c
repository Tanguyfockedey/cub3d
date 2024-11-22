/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:26:48 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/22 12:08:59 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_dir(char dir, t_game *g)
{
	if (dir == 'N')
		g->m.player_dir = NORTH;
	else if (dir == 'E')
		g->m.player_dir = EAST;
	else if (dir == 'S')
		g->m.player_dir = SOUTH;
	else if (dir == 'W')
		g->m.player_dir = WEST;
}

void	find_player(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->m.map[y] != NULL)
	{
		x = 0;
		while (g->m.map[y][x] != '\0')
		{
			if (g->m.map[y][x] == 'N' || g->m.map[y][x] == 'S'
				|| g->m.map[y][x] == 'E' || g->m.map[y][x] == 'W')
			{
				g->p.pos.x = (double)y + 0.5;
				g->p.pos.y = (double)x + 0.5;
				find_dir(g->m.map[y][x], g);
				g->m.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

int	count_pos(t_game *g)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (g->m.map[i])
	{
		j = 0;
		while (g->m.map[i][j])
		{
			if (g->m.map[i][j] == 'N' || g->m.map[i][j] == 'S'
				|| g->m.map[i][j] == 'E' || g->m.map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	else if (count < 1)
		return (printf("Error\nMust be one start pos."), exit(1), 1);
	return (printf("Error\nMust be only one start pos."), exit(1), 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:59:35 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/13 20:07:47 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%c ", map->tiles[i * map->width + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	msleep(int ms)
{
	int	t;

	t = timestamp() + ms;
	while (timestamp() < t)
		usleep(100);
}

void	sleeptill(int t)
{
	while (timestamp() < t)
		usleep(100);
}

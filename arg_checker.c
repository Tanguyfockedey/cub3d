/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:45:15 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/16 16:43:54 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_parser(char *file, t_map *map);
static int	init_map(t_map *map);

int	arg_checker(int argc, char **argv, t_map *map)
{
	int	len;
	int	err;

	if (argc < 2)
		return (err_val(22));
	if (argc > 2)
		return (err_val(7));
	len = ft_strlen(argv[1]);
	if (len < 5 || argv[1][len - 4] != '.'
				|| argv[1][len - 3] != 'c'
				|| argv[1][len - 2] != 'u'
				|| argv[1][len - 1] != 'b')
		return (err_val(22));
	err = map_parser(argv[1], map);
	if (err)
		return (err);
	return (0);
}

static int	map_parser(char *file, t_map *map)
{
	int	fd;

	(void)map;
	if (open(file, O_DIRECTORY) > 0)
		return (err_val(21));
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (err_val(0));
	init_map(map);
	return (0);
}

static int	init_map(t_map *map)
{
	int	x,y;

	map->width = 10;
	map->height = 16;
	if (!(map->tiles = malloc(map->width * sizeof(void*))))
		exit(1);
	for (x = 0; x < map->width; x++)
	{
		if (!(map->tiles[x] = malloc(map->height * sizeof(void*))))
			exit(1);
	}
	for (x = 0; x < map->width; x++)
		map->tiles[x][0] = '1';
	for (y = 1; y < map->height - 1; y++)
	{
		map->tiles[0][y] = '1';
		for (x = 1; x < map->width; x++)
			map->tiles[x][y] = ' ';
		map->tiles[9][y] = '1';
	}
	for (x = 0; x < map->width; x++)
		map->tiles[x][15] = '1';
	map->tiles[4][3] = '1';
	map->tiles[5][3] = '1';
	map->tiles[6][3] = '1';
	map->tiles[5][4] = '1';
	map->tiles[6][11] = '1';
	map->tiles[7][12] = '1';
	map->tiles[8][13] = '1';
	return (0);
}

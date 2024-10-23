/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:45:15 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/23 17:24:27 by tafocked         ###   ########.fr       */
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
	int	i;
	
	i = 0;
	map->width = 10;
	map->height = 10;
	map->tiles = malloc(map->width * map->height * sizeof(char));
	while (i < 100)
	{
		if (i < 10 || (i % 10 == 0) || (i % 10 == 9) || i > 90)
			map->tiles[i] = '1';
		else
			map->tiles[i] = ' ';
		i++;
	}
	map->tiles[32] = '1';
	map->tiles[33] = '1';
	map->tiles[34] = '1';
	map->tiles[43] = '1';
	map->tiles[55] = '1';
	map->tiles[66] = '1';
	map->tiles[77] = '1';
	return (0);
}

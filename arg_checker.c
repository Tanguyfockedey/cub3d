/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:45:15 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/18 18:50:48 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_parser(char *file, t_map *map);


int	arg_checker(int argc, char **argv, t_map *map)
{
	int	len;
	int	err;

	if (argc < 2)
		return (err_msg(22));
	if (argc > 2)
		return (err_msg(7)); 
	len = ft_strlen(argv[1]);
	if (len < 5 || argv[1][len - 4] != '.'
				|| argv[1][len - 3] != 'c'
				|| argv[1][len - 2] != 'u'
				|| argv[1][len - 1] != 'b')
		return(err_msg(22));
	if ((err = map_parser(argv[1], map)))
		return (err);
	return (0);
}

static int	map_parser(char *file, t_map *map)
{
	int	fd;

	(void)map;
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (err_msg(0));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:39 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/21 20:14:36 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_game *g, t_map *map)
{
	print_map(map);
	g->mlx = mlx_init();
	if (!g->mlx)
		return (err_str("Initialisation of mlx failed.", 1));
	g->mlx_win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!g->mlx_win)
		return (err_str("Initilisation of window failed.", 1));
	mlx_loop(g->mlx);
	return (0);
}

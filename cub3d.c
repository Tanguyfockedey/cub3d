/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:18:41 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/21 12:00:57 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	init_game(&game, av, ac);
	mlx_loop_hook(game.w.mlx, render, &game);
	mlx_loop(game.w.mlx);
	
	free_strs(game.m.map);
	free_game(&game);
	//system("leaks cub3D");
	return (0);
}

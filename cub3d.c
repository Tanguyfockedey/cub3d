/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:18:41 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/16 17:38:26 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		err;
	t_game	game;

	err = arg_checker(argc, argv, &game.m); //tmp
	if (err)
		return (err);
	err = init_game(&game);
	if (err)
		return (err);
	mlx_loop_hook(game.w.mlx, render, &game);
	mlx_loop(game.w.mlx);
}

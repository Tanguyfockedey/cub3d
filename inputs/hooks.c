/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:44:36 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/21 15:18:34 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_hook(void)
{
	exit(0);
	return (0);
}

int	key_down_handler(int hook, t_game *g)
{
	if (hook == ESC)
		exit(0);
	else if (hook == R_LEFT)
		g->p.rot_lr = -1;
	else if (hook == R_RIGHT)
		g->p.rot_lr = 1;
	else if (hook == FORWARD)
		g->p.mov_forward = 1;
	else if (hook == BACK)
		g->p.mov_forward = -1;
	else if (hook == LEFT)
		g->p.mov_lr = -1;
	else if (hook == RIGHT)
		g->p.mov_lr = 1;
	return (0);
}

int	key_up_handler(int hook, t_game *g)
{
	if (hook == R_LEFT)
		g->p.rot_lr = 0;
	else if (hook == R_RIGHT)
		g->p.rot_lr = 0;
	else if (hook == FORWARD)
		g->p.mov_forward = 0;
	else if (hook == BACK)
		g->p.mov_forward = 0;
	else if (hook == LEFT)
		g->p.mov_lr = 0;
	else if (hook == RIGHT)
		g->p.mov_lr = 0;
	return (0);
}

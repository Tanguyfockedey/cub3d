/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:17 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/22 19:06:45 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_game *g)
{
	int		i;

	i = 0;
	while (i < g->w.width)
	{
		g->p.camera_x = 2 * i / (double)(g->w.width) - 1;
		g->r.dir_x = g->p.dir_x + g->p.plane_x * g->p.camera_x;
		g->r.dir_y = g->p.dir_y + g->p.plane_y * g->p.camera_x;
		g->r.delta_dist_x = abs(1 / g->r.dir_x);
		g->r.delta_dist_y = abs(1 / g->r.dir_y);
	}
}

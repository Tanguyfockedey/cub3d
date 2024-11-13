/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:17 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/13 19:10:46 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delta_dist(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	if (r->dir_x == 0)
		r->delta_dist_x = 1e300;
	else
		r->delta_dist_x = fabs(1 / r->dir_x);
	if (r->dir_y == 0)
		r->delta_dist_y = 1e300;
	else
		r->delta_dist_y = fabs(1 / r->dir_y);
}

static void	start_dist(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->p.pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (-(g->p.pos_x) + r->map_x + 1) * r->delta_dist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->p.pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (-(g->p.pos_y) + r->map_y + 1) * r->delta_dist_y;
	}
}

static void	dda(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (g->m.tiles[g->m.width * r->map_y + r->map_x] > '0')
			r->hit = 1;
	}
}

static void	wall_dist(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
}

int	cast_rays(t_game *g)
{
	int		ray;

	ray = 0;
	while (ray < g->w.width)
	{
		g->p.camera_x = 2 * ray / (double)(g->w.width) - 1;
		g->r.dir_x = g->p.dir_x + g->p.plane_x * g->p.camera_x;
		g->r.dir_y = g->p.dir_y + g->p.plane_y * g->p.camera_x;
		g->r.map_x = (int)(g->p.pos_x);
		g->r.map_y = (int)(g->p.pos_y);
		delta_dist(g);
		start_dist(g);
		dda(g);
		wall_dist(g);
		draw_wall(g, ray);
		ray++;
	}
	return 0;
}

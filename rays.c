/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:17 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/23 20:46:41 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delta_dist(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	// if (r->dir_x == 0)
	// 	r->delta_dist_x = 1e300;
	// else
		r->delta_dist_x = fabs(1 / r->dir_x);
	// if (r->dir_x == 0)
	// 	r->delta_dist_y = 1e300;
	// else
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
		r->side_dist_x = (-(g->p.pos_x) + r->map_x) * r->delta_dist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->p.pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (-(g->p.pos_y) + r->map_y) * r->delta_dist_y;
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
		if (g->m.tiles[g->m.width * r->map_y + r->map_x] > 0)
			r->hit = 1;
	}
}

static void	wall_height(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
}

void	cast_rays(t_game *g)
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
		if (ray == 0 || ray == 960 || ray ==1910)
			printf("--------------------\np.camera : %f\nr.dir x : %f\nr.dir y : %f\nr.map x : %d\nr.map y : %d\n", g->p.camera_x, g->r.dir_x,g->r.dir_y,g->r.map_x,g->r.map_y);
		delta_dist(g);
		start_dist(g);
		dda(g);
		wall_height(g);
		draw_wall(g, ray);
		if (ray == 0 || ray == 960 || ray ==1910)
			printf("\nr.delta x : %f\nr.delta y : %f\nr.side x : %f\nr.side y : %f\nr.step x : %d\nr.step y : %d\n", g->r.delta_dist_x, g->r.delta_dist_y, g->r.side_dist_x, g->r.side_dist_y, g->r.step_x, g->r.step_y);
		ray++;
	}
	render(g);
}

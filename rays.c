/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:17 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/20 15:04:05 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delta_dist(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	if (r->dir.x == 0)
		r->delta_dist.x = 1e300;
	else
		r->delta_dist.x = fabs(1 / r->dir.x);
	if (r->dir.y == 0)
		r->delta_dist.y = 1e300;
	else
		r->delta_dist.y = fabs(1 / r->dir.y);
}

static void	start_dist(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (g->p.pos.x - r->map.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (-(g->p.pos.x) + r->map.x + 1) * r->delta_dist.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (g->p.pos.y - r->map.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (-(g->p.pos.y) + r->map.y + 1) * r->delta_dist.y;
	}
}

static void	dda(t_game *g)
{
	t_ray	*r;

	r = &g->r;
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map.y += r->step.y;
			r->side = 1;
		}
		if (g->m.map[r->map.x][r->map.y] > '0')
			r->hit = 1;
	}
}

static void	wall_dist(t_game *g)
{
	t_ray	*r;
	double	wall_x;

	r = &g->r;
	if (r->side == 0)
	{
		r->perp_wall_dist = r->side_dist.x - r->delta_dist.x;
		wall_x = g->p.pos.y + r->perp_wall_dist * r->dir.y;
	}
	else
	{
		r->perp_wall_dist = r->side_dist.y - r->delta_dist.y;
		wall_x = g->p.pos.x + r->perp_wall_dist * r->dir.x;
	}
	wall_x = wall_x - (int)wall_x;
	r->tex.x = (int)(wall_x * TEX_WIDTH);
	if (g->r.side == 0 && g->r.dir.x > 0)
		r->tex.x = TEX_WIDTH - r->tex.x - 1;
	if (g->r.side == 1 && g->r.dir.y < 0)
		r->tex.x = TEX_WIDTH - r->tex.x - 1;
}

int	cast_rays(t_game *g)
{
	g->w.pixel.x = 0;
	while (g->w.pixel.x < g->w.width)
	{
		g->p.camera_x = 2 * g->w.pixel.x / (double)(g->w.width) - 1;
		g->r.dir.x = g->p.dir.x + g->p.plane.x * g->p.camera_x;
		g->r.dir.y = g->p.dir.y + g->p.plane.y * g->p.camera_x;
		g->r.map.x = (int)(g->p.pos.x);
		g->r.map.y = (int)(g->p.pos.y);
		delta_dist(g);
		start_dist(g);
		dda(g);
		wall_dist(g);
		draw_wall(g);
		g->w.pixel.x++;
	}
	return (0);
}

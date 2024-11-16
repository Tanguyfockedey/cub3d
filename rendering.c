/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:40 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/16 17:09:40 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_wall(t_game *g, double step, double *tex_pos)
{
	unsigned int	color;

	g->r.tex.y = (int)*tex_pos & (TEX_HEIGHT - 1);
	*tex_pos += step;
	if (g->r.side == 1)
	{
		if (g->r.dir.y < 0)
			color = get_img_color(&g->m.tex_n, &g->r.tex);
		else
			color = get_img_color(&g->m.tex_s, &g->r.tex);
	}
	else
	{
		if (g->r.dir.x < 0)
			color = get_img_color(&g->m.tex_w, &g->r.tex);
		else
			color = get_img_color(&g->m.tex_e, &g->r.tex);
	}
	if (g->r.side == 0)
		color = (color >> 1) & 0x007F7F7F;
	color_pixel(&g->w.buff, &g->w.pixel, color);
}

static int	draw_area(t_game *g, int *draw_start, int *draw_end)
{
	int	line_height;

	line_height = (int)(g->w.height / g->r.perp_wall_dist);
	*draw_start = g->w.height / 2 - line_height / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = *draw_start + line_height;
	if (*draw_end >= g->w.height)
		*draw_end = g->w.height - 1;
	return (line_height);
}

void	draw_wall(t_game *g)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	step;
	double	tex_pos;

	line_height = draw_area(g, &draw_start, &draw_end);
	step = (double)TEX_HEIGHT / (double)line_height;
	tex_pos = (draw_start - g->w.height / 2 + line_height / 2) * step;
	g->w.pixel.y = 0;
	while (g->w.pixel.y < g->w.height)
	{
		if (g->w.pixel.y < draw_start)
			color_pixel(&g->w.buff, &g->w.pixel, g->m.ceiling);
		else if (g->w.pixel.y > draw_end)
			color_pixel(&g->w.buff, &g->w.pixel, g->m.floor);
		else
			texture_wall(g, step, &tex_pos);
		g->w.pixel.y++;
	}
}

int	render(t_game *g)
{
	int	oldtime;

	if (g->p.mov_forward || g->p.mov_lr)
		move(g);
	if (g->p.rot_lr)
		rotate(&g->p, 0.0873);
	cast_rays(g);
	mlx_put_image_to_window(g->w.mlx, g->w.win, g->w.buff.img, 0, 0);
	oldtime = g->w.time;
	sleeptill(g->w.time + 17);
	g->w.time = timestamp();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:40 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/15 19:19:31 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	color_pixel(t_window w, int x_pix, int y_pix, int color)
{
	char	*addr;

	addr = w.addr + (y_pix * w.size_line + x_pix * w.bpp / 8);
	*(unsigned int *)addr = color;
}

void	texture_wall(t_game *g, int col, int i, double step, double *tex_pos)
{
	int	tex_y;
	unsigned int	color;

	tex_y = (int)*tex_pos & (TEX_HEIGHT - 1);
	*tex_pos += step;
	color = get_img_color(&g->m.tex_n, g->r.tex_x, tex_y);
	color_pixel(g->w, col, i, color);
	// if (g->r.side == 0)
	// 	color_pixel(g->w, col, i, 0x000000AA);
	// else
	// 	color_pixel(g->w, col, i, 0x000000FF);
}

void	draw_wall(t_game *g, int col)
{
	int	i;
	int	line_height;
	int	draw_start;
	int	draw_end;
	double	step;
	double	tex_pos;

	line_height = (int)(g->w.height / g->r.perp_wall_dist);
	draw_start = g->w.height / 2 - line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	// draw_end = g->w.height / 2 + line_height / 2;
	draw_end = draw_start + line_height;
	if (draw_end >= g->w.height)
		draw_end = g->w.height - 1;
	step = (double)TEX_HEIGHT / (double)line_height;
	tex_pos = (draw_start - g->w.height / 2 + line_height / 2) * step;
	i = 0;
	while (i < g->w.height)
	{
		if (i < draw_start)
			color_pixel(g->w, col, i, g->m.ceiling); //ceiling
		else if (i > draw_end)
			color_pixel(g->w, col, i, g->m.floor); //floor
		else
			texture_wall(g, col, i, step, &tex_pos);
		i++;
	}
}

int	render(t_game *g)
{
	int oldtime;

	position (g);
	cast_rays(g);
	mlx_put_image_to_window(g->w.mlx, g->w.win, g->w.img, 0, 0);
	oldtime = g->w.time;
	sleeptill(g->w.time + 17);
	g->w.time = timestamp();
	return (0);
}

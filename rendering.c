/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:40 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/14 17:51:33 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	color_pixel(t_window w, int x_pix, int y_pix, int color)
{
	char	*addr;

	addr = w.addr + (y_pix * w.size_line + x_pix * w.bpp / 8);
	*(unsigned int *)addr = color;
}

void	texture_wall(t_game *g, int col, int i)
{
	if (g->r.side == 0)
		color_pixel(g->w, col, i, 0x000000AA);
	else
		color_pixel(g->w, col, i, 0x000000FF);
	
}

void	draw_wall(t_game *g, int col)
{
	int	i;
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(g->w.height / g->r.perp_wall_dist);
	draw_start = -line_height / 2 + g->w.height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + g->w.height / 2;
	if (draw_end >= g->w.height)
		draw_end = g->w.height - 1;
	i = 0;
	while (i < g->w.height)
	{
		if (i < draw_start)
			color_pixel(g->w, col, i, g->m.ceiling); //ceiling
		else if (i > draw_end)
			color_pixel(g->w, col, i, g->m.floor); //floor
		// else if (g->r.side == 0)
		// color_pixel(g->w, col, i, 0x000000AA);
		// 	else
		// color_pixel(g->w, col, i, 0x000000FF);
		else
			texture_wall(g, col, i);
		i++;
	}
}

int	render(t_game *g)
{
	int oldtime;

	position (g);
	cast_rays(g);
	mlx_put_image_to_window(g->w.mlx, g->w.win, g->w.img, 0, 0);
	// mlx_put_image_to_window(g->w.mlx, g->w.win, g->m.wall_n, 0, 0);
	oldtime = g->w.time;
	sleeptill(g->w.time + 17);
	g->w.time = timestamp();
	return (0);
}

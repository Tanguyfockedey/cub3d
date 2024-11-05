/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:40 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/05 19:32:15 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	color_pixel(t_window w, int x_pix, int y_pix, int color)
{
	char	*addr;

	addr = w.addr + (y_pix * w.size_line + x_pix * w.bpp / 8);
	*(unsigned int *)addr = color;
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
			color_pixel(g->w, col, i, 0x00b0faff);
		else if (i > draw_end)
			color_pixel(g->w, col, i, 0x005c0000);
		else if (g->r.side == 0)
			color_pixel(g->w, col, i, 0x000000AA);
		else
			color_pixel(g->w, col, i, 0x000000FF);
		i++;
	}
}

void	render(t_game *g)
{
	mlx_put_image_to_window(g->w.mlx, g->w.win, g->w.img, 0, 0);
}

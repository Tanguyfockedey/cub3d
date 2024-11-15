/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:59:45 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/15 20:47:44 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_game *g)
{
	int	tex_w;
	int	tex_h;

	tex_h = TEX_HEIGHT;
	tex_w = TEX_WIDTH;
	g->m.tex_n.img = mlx_xpm_file_to_image(g->w.mlx, "textures/bricks.xpm", &tex_w, &tex_h);
	g->m.tex_e.img = mlx_xpm_file_to_image(g->w.mlx, "textures/bricks.xpm", &tex_w, &tex_h);
	g->m.tex_s.img = mlx_xpm_file_to_image(g->w.mlx, "textures/rocks.xpm", &tex_w, &tex_h);
	g->m.tex_w.img = mlx_xpm_file_to_image(g->w.mlx, "textures/rocks.xpm", &tex_w, &tex_h);

	g->m.tex_n.addr = mlx_get_data_addr(g->m.tex_n.img, &g->m.tex_n.bpp, &g->m.tex_n.size_line, &g->m.tex_n.endian);
	g->m.tex_e.addr = mlx_get_data_addr(g->m.tex_e.img, &g->m.tex_e.bpp, &g->m.tex_e.size_line, &g->m.tex_e.endian);
	g->m.tex_s.addr = mlx_get_data_addr(g->m.tex_s.img, &g->m.tex_s.bpp, &g->m.tex_s.size_line, &g->m.tex_s.endian);
	g->m.tex_w.addr = mlx_get_data_addr(g->m.tex_w.img, &g->m.tex_w.bpp, &g->m.tex_w.size_line, &g->m.tex_w.endian);
	return (0);
}

unsigned int	get_img_color(t_image *img, t_coord *p)
{
	unsigned int	color;
	char			*addr;

	addr = img->addr + (p->y * img->size_line + p->x * (img->bpp / 8));
	color = *(unsigned int *)addr;
	return (color);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:59:45 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/21 16:09:24 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_texture_helper(t_map *m)
{
	m->tex_n.addr = mlx_get_data_addr
		(m->tex_n.img, &m->tex_n.bpp, &m->tex_n.size_line, &m->tex_n.endian);
	m->tex_e.addr = mlx_get_data_addr
		(m->tex_e.img, &m->tex_e.bpp, &m->tex_e.size_line, &m->tex_e.endian);
	m->tex_s.addr = mlx_get_data_addr
		(m->tex_s.img, &m->tex_s.bpp, &m->tex_s.size_line, &m->tex_s.endian);
	m->tex_w.addr = mlx_get_data_addr
		(m->tex_w.img, &m->tex_w.bpp, &m->tex_w.size_line, &m->tex_w.endian);
	if (!m->tex_n.addr || !m->tex_e.addr || !m->tex_s.addr || !m->tex_w.addr)
	{
		err_str("Initialization of textures failed.", 1);
		exit (1);
	}
}

void	init_texture(t_game *g, t_map *m)
{
	int	tex_w;
	int	tex_h;

	tex_h = TEX_HEIGHT;
	tex_w = TEX_WIDTH;
	m->tex_n.img = mlx_xpm_file_to_image
		(g->w.mlx, g->m.textures.no_t, &tex_w, &tex_h);
	m->tex_e.img = mlx_xpm_file_to_image
		(g->w.mlx, g->m.textures.so_t, &tex_w, &tex_h);
	m->tex_s.img = mlx_xpm_file_to_image
		(g->w.mlx, g->m.textures.we_t, &tex_w, &tex_h);
	m->tex_w.img = mlx_xpm_file_to_image
		(g->w.mlx, g->m.textures.ea_t, &tex_w, &tex_h);
	if (!m->tex_n.img || !m->tex_e.img || !m->tex_s.img || !m->tex_w.img)
	{
		err_str("No texture image address.", 1);
		exit (1);
	}
	init_texture_helper(m);
}

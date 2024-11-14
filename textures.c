/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:59:45 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/14 17:38:18 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_game *g)
{
	int	tex_w;
	int	tex_h;

	tex_h = TEX_HEIGHT;
	tex_w = TEX_WIDTH;
	g->m.tex_n = mlx_xpm_file_to_image(g->w.mlx, "textures/bricks.xpm", &tex_w, &tex_h);
	g->m.tex_e = mlx_xpm_file_to_image(g->w.mlx, "textures/bricks.xpm", &tex_w, &tex_h);
	g->m.tex_s = mlx_xpm_file_to_image(g->w.mlx, "textures/bricks.xpm", &tex_w, &tex_h);
	g->m.tex_w = mlx_xpm_file_to_image(g->w.mlx, "textures/bricks.xpm", &tex_w, &tex_h);
	if (g->m.tex_n == NULL || g->m.tex_e == NULL || g->m.tex_s == NULL || g->m.tex_w == NULL)
	{
		ft_printf("could not initialize textures !\n");
		exit(1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:39 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/16 17:31:22 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_window(t_game *g, t_window *w)
{
	w->width = WIDTH;
	w->height = HEIGHT;
	w->mlx = mlx_init();
	if (!w->mlx)
		return (err_str("Initialisation of mlx failed.", 1));
	w->win = mlx_new_window(w->mlx, w->width, w->height, "Cub3d");
	if (!w->win)
		return (err_str("Initilisation of window failed.", 1));
	w->buff.img = mlx_new_image(w->mlx, w->width, w->height);
	if (!w->buff.img)
		return (err_str("Initialisation of image failed.", 1));
	w->buff.addr = mlx_get_data_addr
		(w->buff.img, &w->buff.bpp, &w->buff.size_line, &w->buff.endian);
	if (!w->buff.addr)
		return (err_str("No image adress.", 1));
	mlx_hook(w->win, EXIT, 0, close_hook, g);
	mlx_hook(w->win, KEY_DOWN, 0, key_down_handler, g);
	mlx_hook(w->win, KEY_UP, 0, key_up_handler, g);
	w->time = timestamp();
	return (0);
}

static int	init_map(t_game *g, t_map *m)
{
	(void)g;
	m->ceiling = 0x00b0faff;
	m->floor = 0x005c0000;
	m->player_dir = NORTH;
	if (init_texture(g, &g->m))
		exit(1);
	return (0);
}

static int	init_player(t_game *g, t_player *p)
{
	p->pos.x = 5.5; // a changer
	p->pos.y = 5.5; // a changer
	p->dir.x = 0;
	p->dir.y = -1;
	p->plane.x = 0.66;
	p->plane.y = 0;
	p->mov_forward = 0;
	p->mov_lr = 0;
	p->rot_lr = 1;
	rotate(p, g->m.player_dir);
	p->rot_lr = 0;
	return (0);
}

int	init_game(t_game *g)
{
	int	err;

	err = init_window(g, &g->w);
	if (err)
		return (1);
	err = init_map(g, &g->m);
	if (err)
		return (1);
	err = init_player(g, &g->p);
	if (err)
		return (1);
	print_map(&g->m);
	return (0);
}

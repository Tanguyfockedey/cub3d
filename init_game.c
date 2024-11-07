/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:39 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/07 15:01:42 by tafocked         ###   ########.fr       */
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
	w->img = mlx_new_image(w->mlx, w->width, w->height);
	if (!w->img)
		return (err_str("Initialisation of image failed.", 1));
	w->addr = mlx_get_data_addr(w->img, &w->bpp, &w->size_line, &w->endian);
	if (!w->addr)
		return (err_str("No image adress.", 1));
//	mlx_key_hook(w->win, key_hook, g);
	mlx_hook(w->win, 17, 0, close_hook, g);
	mlx_hook(w->win, KEY_DOWN, 0, key_down_handler, g);
	mlx_hook(w->win, KEY_UP, 0, key_up_handler, g);
	return (0);
}

static int	init_player(t_game *g, t_player *p)
{
	p->pos_x = 3.5;
	p->pos_y = 5.5;
	p->dir_x = 0;
	p->dir_y = -1;
	p->plane_x = 0.66;
	p->plane_y = 0;
	(void)g;
	return (0);
}

static int	init_map(t_game *g, t_map *m)
{
	(void)g;
	m->floor[0] = 0x0;
	m->floor[1] = 0x5c;
	m->floor[2] = 0x0;
	m->floor[3] = 0x0;
	m->ceiling[0] = 0x0;
	m->ceiling[1] = 0xb0;
	m->ceiling[2] = 0xfa;
	m->ceiling[3] = 0xff;
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

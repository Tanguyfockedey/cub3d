/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:39 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/20 11:45:28 by fimazouz         ###   ########.fr       */
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
	mlx_hook(w->win, KEY_DOWN, 1L << 0, key_down_handler, g);
	mlx_hook(w->win, KEY_UP, 1L << 1, key_up_handler, g);
	w->time = timestamp();
	return (0);
}

static int	map(t_game *g)
{
	char	*line;

	line = parse_map(g->fd, g);
	check_required_elements(g);
	stock_map(line, g);
	size_map(g);
	if (count_pos(g) == 1)
		return (1);
	if (is_wall(g) == 1)
		return (1);
	fill_map(g);
	get_map_size_fill(g);
	is_map_empty(g->m.map);
	if (check_chars(g) == 1)
		return (1);
	find_player(g);
	if (init_texture(g, &g->m))
		exit(1);
	return (0);
}

static int	init_player(t_game *g, t_player *p)
{
	p->dir.x = 0;
	p->dir.y = -1;
	p->plane.x = 0.66;
	p->plane.y = 0;
	p->mov_forward = 0;
	p->mov_lr = 0;
	p->rot_lr = 1;
	rotate(p, g->m.player_dir);//je l'ai changer
	p->rot_lr = 0;
	return (0);
}

int	init_game(t_game *g, char **av, int ac)
{
	int	err;

	if (ac != 2 || open_file(av[1]) == -1 || checkcub(av[1]) == 1)
		return (printf("Error\nProblem wih file"), exit(1), 1);
	err = init_window(g, &g->w);
	if (err)
		return (1);
	err = init_player(g, &g->p);
	if (err)
		return (1);
	g->fd = open_file(av[1]);
	g->o.no = 0;
	g->o.so = 0;
	g->o.we = 0;
	g->o.ea = 0;
	g->o.f = 0;
	g->o.c = 0;
	g->m.width = 0;
	g->m.height = 0;
	map(g);
	print_map(g->m.map);
	return (0);
}

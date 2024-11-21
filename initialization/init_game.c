/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:39 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/21 16:09:59 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	init_window(t_game *g, t_window *w)
{
	w->width = WIDTH;
	w->height = HEIGHT;
	w->mlx = mlx_init();
	if (!w->mlx)
		return (err_str("Initialization of mlx failed.", 1));
	w->win = mlx_new_window(w->mlx, w->width, w->height, "Cub3d");
	if (!w->win)
		return (err_str("Initilization of window failed.", 1));
	w->buff.img = mlx_new_image(w->mlx, w->width, w->height);
	if (!w->buff.img)
		return (err_str("Initialization of image failed.", 1));
	w->buff.addr = mlx_get_data_addr(w->buff.img, &w->buff.bpp,
			&w->buff.size_line, &w->buff.endian);
	if (!w->buff.addr)
		return (err_str("No window image address.", 1));
	mlx_hook(w->win, EXIT, 0, close_hook, g);
	mlx_hook(w->win, KEY_DOWN, 1L << 0, key_down_handler, g);
	mlx_hook(w->win, KEY_UP, 1L << 1, key_up_handler, g);
	w->time = timestamp();
	return (0);
}

static int	init_map(t_game *g, int ac, char **av)
{
	char	*line;

	if (ac != 2 || open_file(av[1]) == -1 || checkcub(av[1]) == 1)
		return (printf("Error\nProblem wih file"), exit(1), 1);
	g->fd = open_file(av[1]); //pourquoi ouvrir le fichier 2x ?
	g->file = av[1]; //je ne vois nulle part ou cette variable est utilisée
	g->m.width = 0;
	g->m.height = 0;
	line = parse_map(g->fd, g);
	check_required_elements(g);
	stock_map(line, g);
	size_map(g);
	is_map_empty(g->m.map);
	if (count_pos(g) == 1)
		return (1);
	if (is_wall(g) == 1)
		return (1);
	fill_map(g);
	get_map_size_fill(g);
	if (check_chars(g) == 1)
		return (1);
	find_player(g);
	init_texture(g, &g->m);
	return (0);
}

static void	init_player(t_game *g, t_player *p)
{
	p->dir.x = 0;
	p->dir.y = -1;
	p->plane.x = 0.66;
	p->plane.y = 0;
	p->mov_forward = 0;
	p->mov_lr = 0;
	p->rot_lr = 1;
	rotate(p, g->m.player_dir);
	p->rot_lr = 0;
}

static void	init_options(t_game *g)
{
	g->o.no = 0;
	g->o.so = 0;
	g->o.we = 0;
	g->o.ea = 0;
	g->o.f = 0;
	g->o.c = 0;
}

void	init_game(t_game *g, char **av, int ac)
{
	init_options(g);
	if (init_map(g, ac, av))
		exit(1);
	if (init_window(g, &g->w))
		exit(1);
	init_player(g, &g->p);
	print_map(g->m.map);
}

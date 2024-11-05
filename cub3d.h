/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:19:10 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/05 19:04:49 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Includes */
# include "includes/libft_updated/libft.h"
# include "includes/libft_updated/printf/ft_printf.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

/* Screen resolution */
# define WIDTH 1000
# define HEIGHT 500

/* Key bindings */
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define R_LEFT 
# define R_RIGHT

typedef struct s_map
{
	char			floor[4];
	char			ceiling[4];
	int			width;
	int			height;
	char		*tiles;
	//N E S W walls
}	t_map;

typedef struct s_window
{
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}	t_window;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	// t_ray		*rays;
}	t_player;

typedef struct s_game
{
	t_window	w;
	t_map		m;
	t_player	p;
	t_ray		r;
}	t_game;

/* Parser */
int		arg_checker(int argc, char **argv, t_map *map);

/* Game */
int		init_game(t_game *game);
int		close_hook(void);
int		key_hook(int hook, t_game *g);
void	cast_rays(t_game *g);
void	draw_wall(t_game *g, int col);
void	render(t_game *g);

/* Utils */
int		err_val(int ret);
int		err_str(char *str, int ret);
void	print_map(t_map *map);

#endif

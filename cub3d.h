/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:19:10 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/13 18:54:01 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Includes */
# include "includes/libft_updated/libft.h"
# include "includes/libft_updated/printf/ft_printf.h"
# ifdef __linux__
#  include "includes/mlx_linux/mlx.h"
# elif __APPLE__
#  include <mlx.h>
# endif
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
# ifdef __linux__

# elif __APPLE__
#  define ESC 53
#  define R_LEFT 123
#  define R_RIGHT 124
#  define LEFT 0
#  define RIGHT 2
#  define BACK 1
#  define FORWARD 13
#  define KEY_DOWN 2
#  define KEY_UP 3
# endif

typedef struct s_map
{
	char		floor[4];
	char		ceiling[4];
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
	double		time;
	double		old_time;
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
	int			mov_forward;
	int			mov_lr;
	int			rot_lr;
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
int		key_down_handler(int hook, t_game *g);
int		key_up_handler(int hook, t_game *g);
void	position(t_game *g);
int		cast_rays(t_game *g);
void	draw_wall(t_game *g, int col);
int		render(t_game *g);
void	rotate(t_player *p);


/* Utils */
int		err_val(int ret);
int		err_str(char *str, int ret);
void	print_map(t_map *map);

#endif

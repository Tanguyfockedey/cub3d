/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:19:10 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/16 17:38:55 by tafocked         ###   ########.fr       */
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
# include <sys/time.h>

/* Screen resolution */
# define WIDTH 1000
# define HEIGHT 500

/* Texture resolution */
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

/* Key bindings */
# ifdef __linux__

# elif __APPLE__
#  define EXIT 17
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
# define NORTH 0
# define EAST 1.57
# define SOUTH 3.142
# define WEST 4.71

/* Structures */
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	int		ceiling;
	int		floor;
	int		width;
	int		height;
	char	**tiles;
	double	player_dir;
	t_image	tex_n;
	t_image	tex_e;
	t_image	tex_s;
	t_image	tex_w;
}	t_map;

typedef struct s_window
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	t_image	buff;
	t_coord	pixel;
	int		time;
}	t_window;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	t_coord		tex;
	t_coord		map;
	t_coord		step;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
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

/* Functions */
int				arg_checker(int argc, char **argv, t_map *map); //temp

/* Color */
void			color_pixel(t_image *img, t_coord *px, int color);
unsigned int	get_img_color(t_image *img, t_coord *px);

/* Error */
int				err_val(int ret); //temp
int				err_str(char *str, int ret); //temp

/* Hooks */
int				close_hook(void);
int				key_down_handler(int hook, t_game *g);
int				key_up_handler(int hook, t_game *g);

/* Init game */
int				init_game(t_game *game); //mod

/* Movememts */
void			rotate(t_player *p, double rot);
void			move(t_game *g);

/* Rays */
int				cast_rays(t_game *g);

/* Rendering */
void			draw_wall(t_game *g);
int				render(t_game *g);

/* Init texture */
int				init_texture(t_game *g, t_map *m); // mod

/* Time */
int				timestamp(void);
void			sleeptill(int t);

/* Utils */
void			print_map(t_map *map); //temp

#endif

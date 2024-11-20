/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:19:10 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/20 14:55:11 by fimazouz         ###   ########.fr       */
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
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* Screen resolution */
# define WIDTH 2000
# define HEIGHT 1000

/* Texture resolution */
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

/* Key bindings */
# ifdef __linux__
#  define EXIT 17
#  define ESC 65307
#  define R_LEFT 65361
#  define R_RIGHT 65363
#  define LEFT 97
#  define RIGHT 100
#  define BACK 115
#  define FORWARD 119
#  define KEY_DOWN 2
#  define KEY_UP 3

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
# define NORTH 0.0
# define EAST 1.57
# define SOUTH 3.142
# define WEST 4.71

/* Structures */
typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_textures
{
	char		*no_t;
	char		*so_t;
	char		*we_t;
	char		*ea_t;
}				t_textures;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			trgb;
}				t_color;

typedef struct s_map
{
	// int		ceiling;
	// int		floor;
	int			width;
	int			height;
	char		**map; // tiles
	double		player_dir;
	t_color		floor;
	t_color		ceiling;
	t_textures	textures;
	t_image		tex_n;
	t_image		tex_e;
	t_image		tex_s;
	t_image		tex_w;
}				t_map;

typedef struct s_window
{
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	t_image		buff;
	t_coord		pixel;
	int			time;
}				t_window;

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
}				t_ray;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		camera_x;
	int			mov_forward;
	int			mov_lr;
	int			rot_lr;
}				t_player;

typedef struct s_options
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
}				t_options;

typedef struct s_game
{
	int			fd;
	t_window	w;
	t_map		m;
	t_player	p;
	t_ray		r;
	t_options	o;
}				t_game;

/* Functions */
/* Color */
void			color_pixel(t_image *img, t_coord *px, int color);
unsigned int	get_img_color(t_image *img, t_coord *px);
/* Error */
int				err_str(char *str, int ret); // temp
/* Hooks */
int				close_hook(void);
int				key_down_handler(int hook, t_game *g);
int				key_up_handler(int hook, t_game *g);
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
/* Checker */
int				checkcub(char *file);
int				check_color(t_color *color);
int				check_required_elements(t_game *g);
int				count_pos(t_game *g);
int				is_wall(t_game *g);
int				check_textures(t_game *g);
int				check_chars(t_game *g);
void			is_map_empty(char **map);
/* Parser */
int				parse_rgb(char *line, t_color *color);
void			parse_texture(char *line, char *id, t_game *g);
void			fill_map(t_game *g);
void			get_map_size_fill(t_game *game);
void			size_map(t_game *g);
void			stock_map(char *line, t_game *g);
int				countcolums(t_game *g);
int				countlines(t_game *g);
void			find_player(t_game *g);
char			*parse_map(int fd, t_game *g);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_free_split(char **array);
/* Helper functions */
int				ft_findspace(char *line);
int				open_file(char *file);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			print_map(char **map);
char			*ft_strcpyy(char *dest, const char *src);
char			*trim_start(char *line);
void			trim_newline(char *line);
/* Free */
void			free_strs(char **strs);
void			free_game(t_game *g);
/* Init */
int				init_game(t_game *g, char **av, int ac);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:19:10 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/19 15:45:08 by fimazouz         ###   ########.fr       */
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

typedef struct s_textures
{
	char		*no_t;
	char		*so_t;
	char		*we_t;
	char		*ea_t;
}				t_textures;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int 	trgb;
}				t_color;

typedef struct s_map
{
	// int		ceiling;
	// int		floor;
	int		width;
	int		height;
	char	**map;//tiles
	double	player_dir;
	t_color		floor;
	t_color		ceiling;
	t_textures	textures;
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
	char		start_direction;
}	t_player;

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




//fonctions fifi
int				checkcub(char *file);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				check_color(t_color *color);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			**ft_split(char const *s, char c);
void			ft_free_split(char **array);
int				parse_rgb(char *line, t_color *color);
int				ft_findspace(char *line);
int				open_file(char *file);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			parse_texture(char *line, char *id, t_game *g);
char			*parse_map(int fd, t_game *g);
int			init_game(t_game *g, char **av, int ac);
int				check_textures(t_game *g);
void			print_map(char **map);
void			*ft_memset(void *ptr, int x, size_t n);
void			get_map_size_and_fill(t_game *game);
char			*ft_strcpyy(char *dest, const char *src);
char			*trim_start(char *line);
void			fill_map(t_game *g);
void			get_map_size_fill(t_game *game);
void			trim_newline(char *line);
int				check_chars(t_game *g);
int				is_map_surrounded_by_walls(t_game *g);
char			*ft_strtrim(char const *s1, char const *set);
void			size_map(t_game *g);
void			stock_map(char *line, t_game *g);
int				countcolums(t_game *g);
int				countlines(t_game *g);
int				check_required_elements(t_game *g);
void			free_strs(char **strs);
void			find_player(t_game *g);
int				count_pos(t_game *g);
void	free_game(t_game *g);

#endif

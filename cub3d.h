/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:19:10 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/18 18:22:27 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes/libft_updated/libft.h"
# include "includes/libft_updated/printf/ft_printf.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

/* Screen resolution */
# define WIDTH 1280
# define HEIGHT 720

/* Key bindings */
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

typedef struct s_map
{
	unsigned char	floor[3];
	unsigned char	ceiling[3];
}	t_map;

int	arg_checker(int argc, char **argv, t_map *map);
int	err_msg(int ret);

#endif

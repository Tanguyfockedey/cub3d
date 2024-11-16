/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:01:31 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/16 16:17:33 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_pixel(t_image *img, t_coord *px, int color)
{
	char	*addr;

	addr = img->addr + (px->y * img->size_line + px->x * img->bpp / 8);
	*(unsigned int *)addr = color;
}

unsigned int	get_img_color(t_image *img, t_coord *px)
{
	unsigned int	color;
	char			*addr;

	addr = img->addr + (px->y * img->size_line + px->x * (img->bpp / 8));
	color = *(unsigned int *)addr;
	return (color);
}

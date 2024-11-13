/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:14:35 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/07 16:14:47 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_player *p)
{
	double		old_dir_x;
	double		old_plane_x;
	double		rot;

	rot = 0.175 * p->rot_lr;
	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;

	p->dir_x = old_dir_x * cos(rot) - p->dir_y * sin(rot);
	p->dir_y = old_dir_x * sin(rot) + p->dir_y * cos (rot);
	p->plane_x = old_plane_x * cos(rot) - p->plane_y * sin(rot);
	p->plane_y = old_plane_x * sin(rot) + p->plane_y * cos(rot);
}

void	move(t_game *g)
{
	t_player	*p;
	int			next_x;
	int			next_y;
	p = &g->p;
	next_x = p->pos_x + (p->dir_x * p->mov_forward * 0.1) - (p->dir_y * p->mov_lr * 0.1);
	next_y = p->pos_y + (p->dir_y * p->mov_forward * 0.1) + (p->dir_x * p->mov_lr * 0.1);
	
	if (g->m.tiles[g->m.width * next_y + next_x] == ' ') //potentiellement remplacer par '0'
	{
		p->pos_x += p->dir_x * p->mov_forward * 0.1;
		p->pos_y += p->dir_y * p->mov_forward * 0.1;
		p->pos_x -= p->dir_y * p->mov_lr * 0.1;
		p->pos_y += p->dir_x * p->mov_lr * 0.1;
	}
	
}

void	position(t_game *g)
{
	if (g->p.mov_forward || g->p.mov_lr)
		move(g);
	if (g->p.rot_lr)
		rotate(&g->p);
}
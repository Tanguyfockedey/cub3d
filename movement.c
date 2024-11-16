/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:14:35 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/16 15:48:17 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_player *p, double rot)
{
	double		old_dir_x;
	double		old_plane_x;

	rot *= p->rot_lr;
	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = old_dir_x * cos(rot) - p->dir.y * sin(rot);
	p->dir.y = old_dir_x * sin(rot) + p->dir.y * cos (rot);
	p->plane.x = old_plane_x * cos(rot) - p->plane.y * sin(rot);
	p->plane.y = old_plane_x * sin(rot) + p->plane.y * cos(rot);
}

static void	move(t_game *g)
{
	t_player	*p;
	t_coord		next;

	p = &g->p;
	next.x = p->pos.x + (p->dir.x * p->mov_forward * 0.1)
		- (p->dir.y * p->mov_lr * 0.1);
	next.y = p->pos.y + (p->dir.y * p->mov_forward * 0.1)
		+ (p->dir.x * p->mov_lr * 0.1);
	if (g->m.tiles[g->m.width * next.y + next.x] == ' ') //potentiellement remplacer par '0'
	{
		p->pos.x += p->dir.x * p->mov_forward * 0.05;
		p->pos.y += p->dir.y * p->mov_forward * 0.05;
		p->pos.x -= p->dir.y * p->mov_lr * 0.05;
		p->pos.y += p->dir.x * p->mov_lr * 0.05;
	}
}

void	position(t_game *g)
{
	if (g->p.mov_forward || g->p.mov_lr)
		move(g);
	if (g->p.rot_lr)
		rotate(&g->p, 0.0873);
}

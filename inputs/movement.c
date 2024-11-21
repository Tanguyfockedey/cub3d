/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:14:35 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/21 15:23:05 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate(t_player *p, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	rot *= p->rot_lr;
	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = old_dir_x * cos(rot) - p->dir.y * sin(rot);
	p->dir.y = old_dir_x * sin(rot) + p->dir.y * cos(rot);
	p->plane.x = old_plane_x * cos(rot) - p->plane.y * sin(rot);
	p->plane.y = old_plane_x * sin(rot) + p->plane.y * cos(rot);
}

void	move(t_game *g)
{
	t_player	*p;
	t_coord		next;

	p = &g->p;
	next.x = p->pos.x + (p->dir.x * p->mov_forward * 0.1) - (p->dir.y
			* p->mov_lr * 0.1);
	next.y = p->pos.y + (p->dir.y * p->mov_forward * 0.1) + (p->dir.x
			* p->mov_lr * 0.1);
	if (g->m.map[next.x][next.y] == '0')
	{
		p->pos.x += p->dir.x * p->mov_forward * 0.05;
		p->pos.y += p->dir.y * p->mov_forward * 0.05;
		p->pos.x -= p->dir.y * p->mov_lr * 0.05;
		p->pos.y += p->dir.x * p->mov_lr * 0.05;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:12:56 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/19 15:13:10 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_game(t_game *g)
{
	if (g->m.textures.no_t)
		free(g->m.textures.no_t);
	if (g->m.textures.so_t)
		free(g->m.textures.so_t);
	if (g->m.textures.we_t)
		free(g->m.textures.we_t);
	if (g->m.textures.ea_t)
		free(g->m.textures.ea_t);
	if (g->fd)
		close(g->fd);
}

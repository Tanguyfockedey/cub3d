/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:12:56 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/21 15:20:50 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

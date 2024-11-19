/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:27 by firdawssema       #+#    #+#             */
/*   Updated: 2024/11/19 18:35:31 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*trim_start(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

void	fill_line(char **line, int width)
{
	int		line_length;
	char	*new_line;

	line_length = ft_strlen(*line);
	if (line_length < width)
	{
		new_line = malloc(width + 1);
		if (!new_line)
			return ;
		ft_strcpyy(new_line, *line);
		ft_memset(new_line + line_length, '1', width - line_length);
		new_line[width] = '\0';
		free(*line);
		*line = new_line;
	}
}

void	size_map(t_game *g)
{
	int	i;
	int	line_length;

	i = 0;
	while (g->m.map[i])
	{
		line_length = ft_strlen(g->m.map[i]);
		if (line_length > g->m.width)
			g->m.width = line_length;
		i++;
	}
	g->m.height = i;
	printf("height : %d \n", g->m.height);
	printf("width : %d ", g->m.width);
}

void	get_map_size_fill(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->m.height)
	{
		fill_line(&game->m.map[i], game->m.width);
		i++;
	}
}

void	fill_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->m.map[i])
	{
		j = 0;
		while (g->m.map[i][j])
		{
			if (g->m.map[i][j] == ' ' || g->m.map[i][j] == '\t')
				g->m.map[i][j] = '1';
			j++;
		}
		i++;
	}
}

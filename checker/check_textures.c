/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:09:27 by firdawssema       #+#    #+#             */
/*   Updated: 2024/11/19 15:30:50 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_findspace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'
			|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
			return (i);
		i++;
	}
	return (-1);
}

int	check_textures(t_game *g)
{
	printf("%s\n", g->m.textures.no_t);
	printf("%s\n", g->m.textures.so_t);
	printf("%s\n", g->m.textures.we_t);
	printf("%s\n", g->m.textures.ea_t);
	if (open_file(g->m.textures.no_t) == -1)
		return (printf("Error\nCould not open NO texture file.\n"), 1);
	if (open_file(g->m.textures.so_t) == -1)
		return (printf("Error\nCould not open SO texture file.\n"), 1);
	if (open_file(g->m.textures.we_t) == -1)
		return (printf("Error\nCould not open WE texture file.\n"), 1);
	if (open_file(g->m.textures.ea_t) == -1)
		return (printf("Error\nCould not open EA texture file.\n"), 1);
	return (0);
}

void	parse_texture(char *line, char *id, t_game *g)
{
	char	*path;

	path = line + ft_strlen(id);
	while (*path == ' ')
		path++;
	if (ft_strcmp(id, "NO") == 0)
		g->m.textures.no_t = ft_strdup(path);
	else if (ft_strcmp(id, "SO") == 0)
		g->m.textures.so_t = ft_strdup(path);
	else if (ft_strcmp(id, "WE") == 0)
		g->m.textures.we_t = ft_strdup(path);
	else if (ft_strcmp(id, "EA") == 0)
		g->m.textures.ea_t = ft_strdup(path);
}
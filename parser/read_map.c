/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:59:36 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/21 11:56:10 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_required_elements(t_game *g)
{
	if (g->o.no == 0 || g->o.so == 0 || g->o.we == 0 || g->o.ea == 0
		|| g->o.f == 0 || g->o.c == 0)
	{
		printf("Error\nMissing one or more required elements :");
		printf("(NO, SO, WE, EA, F,C)\n");
		exit(1);
	}
	return (0);
}

int	is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\n' && *line != '\t')
			return (0);
		line++;
	}
	return (1);
}

int	stock_elem(char *line, t_game *g)
{
	if (ft_strncmp(line, "NO", 2) == 0 && (++g->o.no))
		return (parse_texture(line, "NO", g), 1);
	else if (ft_strncmp(line, "SO", 2) == 0 && (++g->o.so))
		return (parse_texture(line, "SO", g), 1);
	else if (ft_strncmp(line, "WE", 2) == 0 && (++g->o.we))
		return (parse_texture(line, "WE", g), 1);
	else if (ft_strncmp(line, "EA", 2) == 0 && (++g->o.ea))
		return (parse_texture(line, "EA", g), 1);
	else if (ft_strncmp(line, "F", 1) == 0 && (++g->o.f))
		return (parse_rgb(line, &g->m.floor), 1);
	else if (ft_strncmp(line, "C", 1) == 0 && (++g->o.c))
		return (parse_rgb(line, &g->m.ceiling), 1);
	return (0);
}

char	*parse_map(int fd, t_game *g)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (stock_elem(line, g) == 1)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		else
			break ;
		free(line);
		line = get_next_line(fd);
	}
	printf("NO: %d, SO: %d, WE: %d, EA: %d, F: %d, C: %d\n", g->o.no, g->o.so,
		g->o.we, g->o.ea, g->o.f, g->o.c);
	return (line);
}

void	stock_map(char *line, t_game *g)
{
	int	i;

	g->m.map = malloc(sizeof(char *) * INT32_MAX);
	i = 0;
	while (line)
	{
		if (is_empty_line(line))
		{
			printf("Error\nMap shouldn't be separated by a newline");
			exit(1);
		}
		else
		{
			trim_newline(line);
			while (*line == ' ' || *line == '\t')
				line++;
			printf("Ligne de carte lue : %s\n", line);
			g->m.map[i++] = ft_strdup(line);
		}
		// free(line);
		line = get_next_line(g->fd);
	}
	g->m.map[i] = NULL;
}

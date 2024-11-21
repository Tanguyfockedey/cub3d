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

void	create_map(char *line, t_game *g, int lines, int fd)
{
	int	i;

	g->m.map = malloc(sizeof(char *) * lines + 1);
	if (!g->m.map)
		return ;
	i = 0;
	while (line != NULL)
	{
		if (is_empty_line(line))
		{
			printf("Error\nMap shouldn't be separated by a newline.");
			exit(1);
		}
		else
		{
			trim_newline(line);
			// line = trim_start(line);
			printf("Ligne de carte lue : %s\n", line);
			g->m.map[i++] = ft_strdup(line);
			line = get_next_line(g->fd);
		}
	}
	free(line);
	g->m.map[i] = NULL;
	close(fd);
}

void	check_if_line_exists(char *line)
{
	if(line == NULL)
	{
		printf("Error\nEmpty map.");
		exit(1);
	}
}

void	stock_map(char *line, t_game *g)
{
	int		lines;
	char	*cpy_line;
	int		fd;

	check_if_line_exists(line);
	line = trim_start(line);
	cpy_line = ft_strdup(line);
	lines = count_lines_map(line, g);
	fd = open_file(g->file);
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		trim_newline(line);
		while (*line == ' ' || *line == '\t')
			line++;
		if (ft_strncmp(line, cpy_line, ft_strlen(line)) == 0)
			break ;
		line = get_next_line(fd);
	}
	create_map(line, g, lines, fd);
}

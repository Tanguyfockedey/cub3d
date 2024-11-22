/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:59:36 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/22 13:16:39 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_map(char *line, t_game *g, int lines, int fd)
{
	int	i;

	g->m.map = malloc(sizeof(char *) * (lines + 1));
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
	if (line == NULL)
	{
		printf("Error\nEmpty map.");
		exit(1);
	}
}

char	*helper_stock(char *line)
{
	trim_newline(line);
	line = trim_start(line);
	return (line);
}

void	helperstock1(char *line, char **buff, char **cpy_line)
{
	check_if_line_exists(line);
	*buff = ft_strdup(line);
	line = trim_start(line);
	*cpy_line = ft_strdup(line);
}

void	stock_map(char *line, t_game *g)
{
	int		lines;
	char	*cpy_line;
	int		fd;
	char	*buff;

	helperstock1(line, &buff, &cpy_line);
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
		line = helper_stock(line);
		if (ft_strncmp(line, cpy_line, ft_strlen(line)) == 0)
			break ;
		line = get_next_line(fd);
	}
	create_map(buff, g, lines, fd);
}

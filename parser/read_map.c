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

int	count_lines_map(char *line, t_game *g)
{
	int	i;

	i = 0;
	while (line)
	{
		i++;
		//free(line);
		line = get_next_line(g->fd);
	}
	close(g->fd);
	return(i);
}

void	stock_map(char *line, t_game *g)
{
	int		i;
	int 	lines; 
	char	*cpy_line; 
	int		fd;

	
	while (*line == ' ' || *line == '\t')
					line++;
	cpy_line = ft_strdup(line);
	printf("Copy line : %s", cpy_line);
	lines = count_lines_map(line, g);
	fd = open_file(g->file);
	line = get_next_line(fd);
	while(line)
	{
			ft_printf("ḧelloooo");
			if (is_empty_line(line))
			{
				//free(line);
				line = get_next_line(fd);
				continue ;
			}
			trim_newline(line);
			while (*line == ' ' || *line == '\t')
					line++;
			printf(" line : %s  line len : %ld, \ncopy line : %s copy line len : %ld\n", line, ft_strlen(line), cpy_line, ft_strlen(cpy_line));
			if(ft_strncmp(line, cpy_line, ft_strlen(line)) == 0)
					break;
			//free(line);
			line = get_next_line(fd);
	}
	printf("line while : %s\n", line);
	printf("lines : %d\n", lines);
	g->m.map = malloc(sizeof(char *) * lines);
	if(!g->m.map)
		return;
	i = 0;
	ft_printf("cc");
	//free(line);
	// line = get_next_line(fd);
	ft_printf("line ::::::::::::::: %s ", line);
	while (line)
	{
		if (is_empty_line(line))
		{
			printf("Error\nMap shouldn't be separated by a newline.");
			exit(1);
		}
		else
		{
			trim_newline(line);
			while (*line == ' ' || *line == '\t')
					line++;
			printf("Ligne de carte lue : %s\n", line);
			g->m.map[i++] = ft_strdup(line);
			// free(line);
		}
		//free(line);
		line = get_next_line(g->fd);
	}
	g->m.map[i] = NULL;
}

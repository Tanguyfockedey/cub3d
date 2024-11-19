/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:00:40 by firdawssema       #+#    #+#             */
/*   Updated: 2024/11/19 15:29:39 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color(t_color *color)
{
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		printf("Error\nColor values must be between 0 and 255\n");
		exit(1);
	}
	return (0);
}

int	is_numeric(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_arraylen(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

void	parse_helper(char **values, t_color *color)
{
	if (!is_numeric(values[0]) || !is_numeric(values[1])
		|| !is_numeric(values[2]))
		return (printf("Error\nColor values must be numeric\n"), exit(1));
	color->r = ft_atoi(values[0]);
	color->g = ft_atoi(values[1]);
	color->b = ft_atoi(values[2]);
	check_color(color);
	// int i = 0;
	// i = r << 8;
	// i += g << 8;
	// i += b;
	// g->m.floor = i;
}

int	parse_rgb(char *line, t_color *color)
{
	char	**values;
	char	*path;
	int		l;
	int		i;
	char	*trim;

	path = line + 1;
	while (*path == ' ')
		path++;
	l = ft_strlen(path);
	if (path[l - 1] == '\n')
		path[l - 1] = '\0';
	values = ft_split(path, ',');
	if (!values || ft_arraylen(values) != 3)
		return (printf("Error\nInvalid color format\n"), exit(1), 1);
	i = -1;
	while (++i < 3)
	{
		trim = ft_strtrim(values[i], " ");
		if (!trim)
			return (ft_free_split(values), exit(1), 1);
		free(values[i]);
		values[i] = trim;
	}
	return (parse_helper(values, color), ft_free_split(values), 0);
}

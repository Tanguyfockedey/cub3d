/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:54:40 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/20 11:40:45 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_chars(t_game *g)
{
	int		y;
	int		x;
	char	*valid_chars;
	char	*str;

	valid_chars = "10NSEW";
	y = 0;
	while (g->m.map[y])
	{
		x = 0;
		while (g->m.map[y][x])
		{
			str = ft_strchr(valid_chars, g->m.map[y][x]);
			if (!str)
			{
				printf("Error\nInvalid char in map :");
				printf(" '%c'", g->m.map[y][x]);
				exit(1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

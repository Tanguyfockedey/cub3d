/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:51:48 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/19 14:53:08 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*ft_strcpyy(char *dest, const char *src)
{
	char	*d;

	d = dest;
	while ((*src))
		*d++ = *src++;
	return (dest);
}


int	countcolums(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g->m.map[i][j] != '\n' && g->m.map[i][j] != '\0')
		j++;
	return (i);
}

int	countlines(t_game *g)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (g->m.map[i])
	{
		if (g->m.map[i][j] == '\n')
			count++;
		i++;
	}
	count++;
	return (count);
}
void	trim_newline(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	while (len >= 0 && (line[len] == '\n' || line[len] == ' '))
	{
		line[len] = '\0';
		len--;
	}
}

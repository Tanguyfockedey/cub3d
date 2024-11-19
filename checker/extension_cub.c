/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:44:18 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/19 14:59:37 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int	ft_strcub(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i] != '.')
		i++;
	while (needle[j] && haystack[i])
	{
		if (needle[j] == haystack[i])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	if (needle[j] == '\0' && haystack[i] != '\0')
		return (0);
	if (needle[j] != '\0' && haystack[i] == '\0')
		return (0);
	return (1);
}

int	checkcub(char *file)
{
	if (ft_strcub(file, ".cub") == 1)
		return (0);
	else
	{
		printf("Error\nMap must have .cub extension");
		exit(1);
	}
}

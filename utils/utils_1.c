/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:53:19 by fimazouz          #+#    #+#             */
/*   Updated: 2024/11/19 15:48:41 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL || map[0] == NULL)
	{
		printf("Error\nMap is empty.");
		exit(1);
	}
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("fini	u bgjntvru ny hrejucns gersucgrue");
}

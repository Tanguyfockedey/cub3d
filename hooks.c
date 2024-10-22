/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:44:36 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/22 13:56:31 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_hook(void)
{
	exit(0);
	return (0);
}

int	key_hook(int hook, t_game *g)
{
	if (hook == ESC)
		exit(0);
	(void)g;
	return (0);
}

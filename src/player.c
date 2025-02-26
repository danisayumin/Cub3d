/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joscarlo <joscarlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:52:21 by joscarlo          #+#    #+#             */
/*   Updated: 2025/02/25 20:36:05 by joscarlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_player(char *line)
{
	int	index;
	int	num;

	num = 0;
	while (*line != '\0')
	{
		index = 0;
		while (VALID_CHAR_SET_PLAYER[index] != '\0')
		{
			if (*line == VALID_CHAR_SET_PLAYER[index])
			{
				num++;
				break ;
			}
			index++;
		}
		line++;
	}
	return (num);
}

void	move_player(t_cub3d *cub3d, double speed, int signal)
{
	double	x_speed;
	double	y_speed;

	if (signal == 0)
	{
		x_speed = cub3d->dir.x * speed;
		y_speed = cub3d->dir.y * speed;
	}
	else
	{
		x_speed = -signal * cub3d->dir.y * speed;
		y_speed = signal * cub3d->dir.x * speed;
	}
	if ((cub3d->player.x + x_speed + get_signal(x_speed)) > WALL_OFFSET
		&& (cub3d->player.x + x_speed + get_signal(x_speed)) < (cub3d->map_x
			- 1 - WALL_OFFSET))
		cub3d->player.x += x_speed;
	if ((cub3d->player.y + y_speed + get_signal(y_speed)) > WALL_OFFSET
		&& (cub3d->player.y + y_speed + get_signal(y_speed)) < (cub3d->map_y
			- WALL_OFFSET))
		cub3d->player.y += y_speed;
}

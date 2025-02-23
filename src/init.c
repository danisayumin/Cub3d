/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:06:52 by dsayumi-          #+#    #+#             */
/*   Updated: 2025/02/23 15:17:20 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = mlx_init(WIDTH, HEIGHT, GAME_NAME, false);
	if (cub3d->mlx_ptr == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	cub3d->image = mlx_new_image(cub3d->mlx_ptr, WIDTH, HEIGHT);
	if (cub3d->image == NULL)
	{
		mlx_close_window(cub3d->mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(cub3d->mlx_ptr, cub3d->image, 0, 0) == -1)
	{
		mlx_close_window(cub3d->mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	start_params(t_cub3d *cub3d)
{
	cub3d->dir.x = 0;
	cub3d->dir.y = -1;
	cub3d->plane.x = 0.66;
	cub3d->plane.y = 0;
	cub3d->west_texture = NULL;
	cub3d->north_texture = NULL;
	cub3d->east_texture = NULL;
	cub3d->south_texture = NULL;
	cub3d->floor_color = -1;
	cub3d->ceiling_color = -1;
}
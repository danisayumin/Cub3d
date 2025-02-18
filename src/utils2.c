/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:31:40 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/17 23:39:35 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_exit(char *str)
{
	ft_printf(STDERR_FILENO, str);
	exit(EXIT_FAILURE);
}

void	free_texture(t_cub3d *cub3d)
{
	if (cub3d->south_texture != NULL)
		mlx_delete_texture(cub3d->south_texture);
	if (cub3d->north_texture != NULL)
		mlx_delete_texture(cub3d->north_texture);
	if (cub3d->west_texture != NULL)
		mlx_delete_texture(cub3d->west_texture);
	if (cub3d->east_texture != NULL)
		mlx_delete_texture(cub3d->east_texture);
}

void	close_err_exit(int fd, char *str)
{
	close(fd);
	ft_printf(STDERR_FILENO, str);
	exit(EXIT_FAILURE);
}

void	close_free_err_exit(int fd, char **arr, char *err_message)
{
	ft_free_split(arr);
	close_err_exit(fd, err_message);
}

void	free_map_and_texture(t_cub3d *cub3d)
{
	ft_free_split(cub3d->map);
	free_texture(cub3d);
	exit(EXIT_FAILURE);
}
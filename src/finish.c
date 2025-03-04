/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:15:48 by danielasayu       #+#    #+#             */
/*   Updated: 2025/03/03 23:32:10 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	err_exit(char *str)
{
	ft_fprintf(STDERR_FILENO, "%s\n", str); //primeiro parâmetro pode ser STDERR_FILENO
	exit(EXIT_FAILURE);
}

void	close_err_exit(int fd, char *str)
{
	close(fd);
	ft_fprintf(STDERR_FILENO, "%s\n", str); //primeiro parâmetro pode ser STDERR_FILENO
	exit(EXIT_FAILURE);
}

void	close_free_err_exit(int fd, char **arr, char *err_message)
{
	ft_free_split(arr);
	close_err_exit(fd, err_message);
}

void	free_for_finish(t_cub3d *cub3d)
{
	free_texture(cub3d);
	ft_free_split(cub3d->map);
	mlx_delete_image(cub3d->mlx_ptr, cub3d->image);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:46:07 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/17 23:16:59 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_cub3d *cub3d, mlx_texture_t **texture, int fd,
		char **words)
{
	if (*texture != NULL)
	{
		free_gnl_memory(fd);
		free_texture(cub3d);
		close_free_err_exit(fd, words, "Invalid duplicated texture\n");
	}
	*texture = mlx_load_png(words[1]);
	if (*texture == NULL)
	{
		free_gnl_memory(fd);
		free_texture(cub3d);
		close_free_err_exit(fd, words, "Invalid map texture\n");
	}
	ft_free_split(words);
}

static void	check_params_map(t_cub3d *cub3d, int fd, char *str)
{
	char	**words;
	size_t	size;

	words = ft_split_size(str, ' ', &size);
	free(str);
	if (size != 2)
		invalid_parameter_exit(cub3d, fd, words, "Invalid params");
	if (!ft_strncmp(words[0], NORTH, 3))
		load_texture(cub3d, &cub3d->north_texture, fd, words);
	else if (!ft_strncmp(words[0], SOUTH, 3))
		load_texture(cub3d, &cub3d->south_texture, fd, words);
	else if (!ft_strncmp(words[0], WEST, 3))
		load_texture(cub3d, &cub3d->west_texture, fd, words);
	else if (!ft_strncmp(words[0], EAST, 3))
		load_texture(cub3d, &cub3d->east_texture, fd, words);
	else if (!ft_strncmp(words[0], FLOOR, 2))
		load_color(cub3d, &cub3d->floor_color, fd, words);
	else if (!ft_strncmp(words[0], CEILING, 2))
		load_color(cub3d, &cub3d->ceiling_color, fd, words);
	else
		invalid_parameter_exit(cub3d, fd, words, "Invalid map texture or map color\n");
}

void	load_color(t_cub3d *cub3d, int64_t *color, int fd, char **words)
{
	size_t	size;
	char	**colors;

	if (*color != -1)
	{
		free_texture(cub3d);
		free_gnl_memory(fd);
		close_free_err_exit(fd, words, "Invalid duplicated color\n");
	}
	colors = ft_split_size(words[1], ',', &size);
	if (size != 3)
	{
		ft_free_split(colors);
		free_texture(cub3d);
		free_gnl_memory(fd);
		close_free_err_exit(fd, words, "Invalid color\n");
	}
	*color = parse_color(colors, cub3d, fd, words);
	ft_free_split(colors);
}

static uint32_t	parse_color(char **colors, t_cub3d *cub3d, int fd,
		char **words)
{
	size_t		i;
	u_int32_t	color;
	int			current_color;
	bool		has_err;

	i = 0;
	color = 0;
	while (i < 3)
	{
		current_color = ft_safe_atoi(colors[i], &has_err);
		if (current_color < 0 || current_color > 255 || has_err)
		{
			ft_free_split(colors);
			free_texture(cub3d);
			free_gnl_memory(fd);
			close_free_err_exit(fd, words, "Invalid color\n");
		}
		color = (color << 8) | current_color;
		i++;
	}
	ft_free_split(words);
	color = (color << 8) | 0xFF;
	return (color);
}

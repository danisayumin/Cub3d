/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:02:37 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/23 15:17:40 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	parse_parameters(t_cub3d *cub3d, int fd, char **map_line)
{
	char	*line;
	size_t	read_lines;

	read_lines = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free_texture(cub3d);
			close_err_exit(fd, "Missing parameters\n");
		}
		read_lines++;
		line = remove_new_line(line);
		if (!is_empty_line(line))
			check_params_map(cub3d, fd, line);
		else
			free(line);
		if (cub3d->south_texture != NULL && cub3d->south_texture != NULL
			&& cub3d->west_texture != NULL && cub3d->east_texture != NULL
			&& cub3d->ceiling_color != -1 && cub3d->floor_color != -1)
			break ;
	}
	return (read_lines + skip_empty_lines(cub3d, fd, map_line));
}

static void	invalid_parameter_exit(t_cub3d *cub3d, int fd, char **words,
		char *str)
{
	free_gnl_memory(fd);
	free_texture(cub3d);
	close_free_err_exit(fd, words, str);
}
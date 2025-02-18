/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    map.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:16:10 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/14 00:16:26 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(t_cub3d *cub3d, char *map_file)
{
	size_t	lines_size;
	int		fd;
	char	*line;

	lines_size = get_file_size(map_file);
	if (lines_size == 0)
		err_exit("Empty file\n");
	fd = open(map_file, O_RDONLY);
	lines_size -= parse_parameters(cub3d, fd, &line);
	cub3d->map = malloc((lines_size + 1) * sizeof(char *));
	if (cub3d->map == NULL)
		err_exit("Malloc error\n");
	cub3d->map[lines_size] = NULL;
	cub3d->map_y = lines_size;
	lines_size = 0;
	while (true)
	{
		cub3d->map[lines_size++] = line;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	close(fd);
}
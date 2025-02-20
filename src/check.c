/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:23:36 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/20 00:18:05 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	valid_open_wall(t_cub3d *cub3d, size_t x, size_t y)
{
	if (cub3d->map[y][x] == '0')
	{
		if (x == 0 || cub3d->map[y][x + 1] == '\0')
		{
			ft_free_split(cub3d->map);
			free_texture(cub3d);
			err_exit("invalid map");
		}
		if (cub3d->map[y + 1][x] == ' ' || cub3d->map[y - 1][x] == ' '
			|| cub3d->map[y][x + 1] == ' ' || cub3d->map[y][x - 1] == ' ')
		{
			ft_free_split(cub3d->map);
			free_texture(cub3d);
			err_exit("invalid map");
		}
	}
}

void	valid_walls(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;

	if (valid_charset(cub3d->map[0], VALID_WALLS_CHAR_SET) != NULL
		|| valid_charset(cub3d->map[cub3d->map_y - 1],
			VALID_WALLS_CHAR_SET) != NULL)
	{
		free_texture(cub3d);
		ft_free_split(cub3d->map);
		err_exit("invalid open map");
	}
	y = 1;
	while (y < (cub3d->map_y - 1))
	{
		x = 0;
		while (cub3d->map[y][x] != '\0')
		{
			valid_open_wall(cub3d, x, y);
			x++;
		}
		y++;
	}
}

char	*valid_args(int argc, char **argv)
{
	size_t	filename_size;
	size_t	extension_size;

	if (argc != 2)
		err_exit("Invalid number of arguments\n");
	filename_size = ft_strlen(argv[1]);
	extension_size = ft_strlen(".cub");
	if (filename_size < extension_size)
		err_exit("Invalid filename\n");
	while (extension_size--)
	{
		if (argv[1][--filename_size] != FILE_EXTENSION[extension_size])
			err_exit("Invalid filename\n");
	}
	return (argv[1]);
}

void	valid_map(t_cub3d *cub3d)
{
	size_t	y;
	size_t	player_count;
	char	*invalid_char;

	y = 0;
	player_count = 0;
	while (y < cub3d->map_y)
	{
		invalid_char = valid_charset(cub3d->map[y], VALID_CHAR_SET);
		if (invalid_char != NULL)
		{
			ft_printf(STDERR_FILENO, "invalid char", *invalid_char);
			free_map_and_texture(cub3d);
		}
		get_player_position(cub3d, cub3d->map[y - 1], y - 1);
	}
	if (player_count != 1)
	{
		ft_printf(STDERR_FILENO, "invalid player", player_count);
		free_map_and_texture(cub3d);
	}
	valid_walls(cub3d);
}

char	*valid_charset(char *str, char *set)
{
	size_t	index;

	while (*str != '\0')
	{
		index = 0;
		while (set[index] != '\0')
		{
			if (set[index] == *str)
				break ;
			index++;
		}
		if (set[index] == '\0')
			break ;
		str++;
	}
	if (*str == '\0')
		return (NULL);
	return (str);
}

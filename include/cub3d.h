/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:06:52 by dsayumi-          #+#    #+#             */
/*   Updated: 2025/02/17 23:28:52 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "./lib/MLX42/mlx.h"
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

# define WIDTH 1280
# define HEIGHT 720
# define PLAYER_SPEED 0.1
# define PLAYER_ROTATE_SPEED 0.06
# define WALL_OFFSET 0.3

# define GAME_NAME "Cubiculo"
# define VALID_CHAR_SET "01NSEW\n "
# define NOT_PLAYER_CHAR_SET "01 "
# define VALID_CHAR_SET_PLAYER "NSEW"
# define VALID_WALLS_CHAR_SET "1 "
# define FILE_EXTENSION ".cub"

# define WEST "WE"
# define NORTH "NO"
# define EAST "EA"
# define SOUTH "SO"
# define FLOOR "F"
# define CEILING "C"

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_draw_wall
{
	int				tex_x;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_y;
	int				color;
	double			wall_x;
	double			step;
	double			tex_pos;
}					t_draw_wall;

typedef struct s_ray_calc
{
	int				x;
	int				side;
	double			camera_x;
	double			perp_wall_dist;
	t_vector		ray;
	t_vector		delta_dist;
	t_vector		side_dist;
	t_vector		step;
	t_vector		map;
	t_vector		map_point;
	t_vector		dir_point;
}					t_ray_calc;

typedef struct s_cub3d
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*image;
	char			**map;
	size_t			map_x;
	size_t			map_y;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*south_texture;
	int64_t			floor_color;
	int64_t			ceiling_color;
	t_vector		player;
	t_vector		dir;
	t_vector		plane;
}					t_cub3d;

//init
void				initialize(t_cub3d *cub3d);
void				start_params(t_cub3d *cub3d);

//utils
size_t				get_file_size(char *map_file);

// utils2
void				free_for_finish(t_cub3d *cub3d);
void				err_exit(char *str);
void				close_err_exit(int fd, char *str);
void				close_free_err_exit(int fd, char **arr, char *err_message);
void				free_texture(t_cub3d *cub3d);
void				free_map_and_texture(t_cub3d *cub3d);

// map
void				read_map(t_cub3d *cub3d, char *map_file);
void				get_player_position(t_cub3d *cub3d, char *line,
						size_t current_y);
void				normalize_map(t_cub3d *cub3d);

// load
void				load_texture(t_cub3d *cub3d, mlx_texture_t **texture,
						int fd, char **words);
void				load_color(t_cub3d *cub3d, int64_t *color, int fd,
						char **words);

#endif
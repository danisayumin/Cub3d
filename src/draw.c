/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:15:09 by joscarlo          #+#    #+#             */
/*   Updated: 2025/03/01 16:19:52 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_wallpaper(t_cub3d *cub3d, int32_t floor_color,
		int32_t ceiling_color)
{
	t_vector	vector;
	uint32_t	color;

	vector.y = 0;
	color = ceiling_color;
	while (vector.y < cub3d->mlx_ptr->height)
	{
		vector.x = 0;
		if (vector.y > cub3d->mlx_ptr->height / 2)
			color = floor_color;
		while (vector.x < cub3d->mlx_ptr->width)
		{
			mlx_put_pixel(cub3d->image, vector.x, vector.y, color);
			vector.x++;
		}
		vector.y++;
	}
}

static void	draw_tex_wall(t_cub3d *cub3d, t_ray_calc *ray_calc,
		t_draw_wall *draw_wall, mlx_texture_t *texture)
{
	int	y;

	y = draw_wall->draw_start;
	while (y < draw_wall->draw_end)
	{
		draw_wall->tex_y = (int)draw_wall->tex_pos;
		if (draw_wall->tex_y > (int)texture->height - 1)
			draw_wall->tex_y = texture->height - 1;
		draw_wall->tex_pos += draw_wall->step;
		draw_wall->color = rgb_to_int(&texture->pixels[(texture->height
					* draw_wall->tex_y + draw_wall->tex_x)
				* texture->bytes_per_pixel]);
		mlx_put_pixel(cub3d->image, ray_calc->x, y, draw_wall->color);
		y++;
	}
}

void	draw_center_vertical_line(t_cub3d *cub3d, t_ray_calc *ray_calc,
		mlx_texture_t *texture)
{
	t_draw_wall	draw_wall;

	if (ray_calc->side == 0)
		draw_wall.wall_x = cub3d->player.y + ray_calc->perp_wall_dist
			* ray_calc->ray.y;
	else
		draw_wall.wall_x = cub3d->player.x + ray_calc->perp_wall_dist
			* ray_calc->ray.x;
	draw_wall.wall_x -= floor(draw_wall.wall_x);
	draw_wall.tex_x = (int)(draw_wall.wall_x * (double)(texture->width));
	draw_wall.line_height = (int)(cub3d->mlx_ptr->height
			/ ray_calc->perp_wall_dist);
	draw_wall.draw_start = -draw_wall.line_height / 2 + cub3d->mlx_ptr->height
		/ 2;
	if (draw_wall.draw_start < 0)
		draw_wall.draw_start = 0;
	draw_wall.draw_end = draw_wall.line_height / 2 + cub3d->mlx_ptr->height / 2;
	if (draw_wall.draw_end >= cub3d->mlx_ptr->height)
		draw_wall.draw_end = cub3d->mlx_ptr->height - 1;
	draw_wall.step = (double)texture->height / draw_wall.line_height;
	draw_wall.tex_pos = (draw_wall.draw_start - cub3d->mlx_ptr->height / 2
			+ draw_wall.line_height / 2) * draw_wall.step;
	draw_tex_wall(cub3d, ray_calc, &draw_wall, texture);
}

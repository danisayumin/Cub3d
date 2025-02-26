/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:53:20 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/26 15:53:33 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	safe_ray_dist_calc(double ray)
{
	if (ray == 0)
		return (DBL_MAX);
	return (fabs(1 / ray));
}

int	get_signal(double num)
{
	if (num < 0)
		return (-1);
	return (1);
}

uint32_t	rgb_to_int(uint8_t *rgb)
{
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:58:10 by dsayumi-          #+#    #+#             */
/*   Updated: 2025/02/17 23:32:05 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char** argv)
{
	t_cub3d	cub3d;

	start_params(&cub3d);
	read_map(&cub3d, valid_args(argc, argv));
	normalize_map(&cub3d);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:23:36 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/17 23:28:22 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
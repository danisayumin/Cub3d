/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:42:24 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/08/18 21:26:16 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_putptr(unsigned long nbr, int i)
{
	int	count;

	count = 1;
	if (nbr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (i == 0)
	{
		ft_putstr("0x");
		count += 2;
	}
	if (nbr > 15)
		count += ft_putptr(nbr / 16, ++i);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}

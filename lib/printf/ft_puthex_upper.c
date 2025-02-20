/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:32:23 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/08/18 21:41:39 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	int	count;

	count = 1;
	if (n > 15)
		count += ft_puthex_upper(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (count);
}

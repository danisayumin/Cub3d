/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:38:13 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/08/18 21:40:58 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_puthex_low(unsigned int n)
{
	int	count;

	count = 1;
	if (n > 15)
		count += ft_puthex_low(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
	return (count);
}

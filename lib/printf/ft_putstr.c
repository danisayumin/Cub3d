/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:13:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/08/17 21:54:07 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

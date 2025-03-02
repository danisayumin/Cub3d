/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:03:04 by danielasayu       #+#    #+#             */
/*   Updated: 2025/03/01 16:09:57 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


static bool	verify_overflow(int number, int digit, int multiplyer)
{
	if (multiplyer == 1 && number > (INT_MAX - digit) / 10)
		return (true);
	else if (number < (INT_MIN + digit) / 10)
		return (true);
	return (false);
}

// bool	ft_isspace(char c)
// {
// 	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
// 		|| c == '\r')
// 		return (1);
// 	return (0);
// }

int	ft_safe_atoi(const char *nptr, bool *has_err)
{
	size_t	i;
	int		number;
	int		multiplyer;

	i = 0;
	number = 0;
	multiplyer = 1;
	*has_err = false;
	while (nptr[i] != '\0' && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '\0')
	{
		*has_err = true;
		return (number);
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			multiplyer *= -1;
	while (ft_isdigit(nptr[i]))
	{
		*has_err = verify_overflow(number, (nptr[i] - '0'), multiplyer);
		number = (number * 10) + (multiplyer * (nptr[i++] - '0'));
	}
	*has_err = (nptr[i] != '\0');
	return (number);
}

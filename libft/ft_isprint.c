/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joscarlo <joscarlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:02:46 by joscarlo          #+#    #+#             */
/*   Updated: 2023/05/06 14:03:10 by joscarlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

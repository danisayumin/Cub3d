/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:56:19 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/08/18 21:42:09 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_strlen(const char *s);
char	ft_putptr(unsigned long nbr, int i);
int		ft_putunsign(unsigned int nbr);
int		ft_puthex_upper(unsigned int n);
int		ft_puthex_low(unsigned int n);
int		ft_putstr(char *s);
int		convert_params(char *str, int i, va_list vl);

#endif

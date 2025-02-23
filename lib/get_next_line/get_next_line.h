/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:04:29 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/07/10 20:06:56 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(const int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 
#endif

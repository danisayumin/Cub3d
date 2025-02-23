/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:53 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/07/10 21:11:29 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char		*get_next_line(const int fd);
char		*ft_strchr(const char *s, int c);
static char	*line_break(int fd, char *buf, char *remainder);
static char	*ft_split_line(char *line);

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;

	ch = (char)c;
	str = (char *)s;
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}

static char	*line_break(int fd, char *buf, char *remainder)
{
	int		bytes;

	bytes = 0;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(remainder), NULL);
		else if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		remainder = ft_strjoin(remainder, buf);
		if (ft_strchr(remainder, '\n'))
			break ;
	}
	return (remainder);
}

static char	*ft_split_line(char *line)
{
	int		i;
	int		j;
	char	*rest_memory;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	rest_memory = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*rest_memory == '\0')
	{
		free(rest_memory);
		rest_memory = NULL;
	}
	line[i + 1] = '\0';
	return (rest_memory);
}

char	*get_next_line(const int fd)
{
	char			*line;
	char			*buf;
	static char		*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = line_break(fd, buf, remainder);
	free(buf);
	if (line == NULL)
		return (line);
	remainder = ft_split_line(line);
	return (line);
}

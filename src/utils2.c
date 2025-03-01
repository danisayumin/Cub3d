/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:55:34 by danielasayu       #+#    #+#             */
/*   Updated: 2025/03/01 16:08:13 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**get_memory(void)
{
	static char	*memory[4096];

	return (memory);
}

void	free_gnl_memory(int fd)
{
	char	**memory;

	memory = get_memory();
	if (memory[fd] != NULL)
	{
		free(memory[fd]);
		memory[fd] = NULL;
	}
}

void	ft_free_split(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static size_t	count_letters(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	**split_words(char **words, size_t words_len, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	current_char;

	i = 0;
	current_char = 0;
	while (i < words_len)
	{
		j = 0;
		while (s[current_char] == c)
			current_char++;
		words[i] = malloc((count_letters((s + current_char), c) + 1)
				* sizeof(char));
		if (words[i] == NULL)
			return (NULL);
		while (s[current_char] != c && s[current_char] != '\0')
			words[i][j++] = s[current_char++];
		words[i][j] = '\0';
		i++;
	}
	words[words_len] = NULL;
	return (words);
}

char	**ft_split_size(char const *s, char c, size_t *size)
{
	char	**words;
	size_t	words_len;

	words_len = count_words(s, c);
	words = malloc((words_len + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	if (size != NULL)
		*size = words_len;
	return (split_words(words, words_len, s, c));
}

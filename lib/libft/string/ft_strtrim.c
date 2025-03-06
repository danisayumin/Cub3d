/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:50:42 by dsayumi-          #+#    #+#             */
/*   Updated: 2025/03/06 17:50:44 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char const	*end;

	end = s1 + ft_strlen(s1);
	while (*s1 != '\0')
	{
		if (ft_strchr(set, *s1) == NULL)
			break ;
		s1++;
	}
	while (end != s1)
	{
		if (ft_strchr(set, *(end - 1)) == NULL)
			break ;
		end--;
	}
	str = malloc((end - s1 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if ((end - s1 + 1) <= 0)
		return (ft_strdup(""));
	ft_strlcpy(str, s1, end - s1 + 1);
	return (str);
}

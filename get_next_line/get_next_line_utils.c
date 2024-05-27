/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:51:43 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/27 18:48:15 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



void	free_that(char **to_free)
{
	if (*to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char		*str;
	size_t		len;
	size_t		index;

	if (!s)
		return (NULL);
	index = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (index < len)
	{
		str[index] = s[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	index;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	len = 0;
	while (s1[index] != '\0')
		index++;
	while (s2[len] != '\0')
		len++;
	str = malloc((len + index) + 1);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
		str[index++] = *s1++;
	while (*s2 != '\0')
		str[index++] = *s2++;
	str[index] = '\0';
	return (str);
}

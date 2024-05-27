/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:51:43 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/27 21:23:02 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*go_through_file(int fd, char **line)
{
	char	*buffer;
	char	*temp;
	ssize_t	check;
	size_t	index;

	index = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_that(line), NULL);
	check = read(fd, temp, BUFFER_SIZE);
	if (check < 1)
		return (free_that(&temp), NULL);
	temp[check] = '\0';
	buffer = malloc(check + 1);
	if (!buffer)
		return (free_that(&temp), NULL);
	while (temp[index] != '\0')
	{
		buffer[index] = temp[index];
		index++;
	}
	buffer[index] = '\0';
	free_that(&temp);
	return (buffer);
}

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
	char	*str;
	size_t	len;
	size_t	index;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:14 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/23 20:45:33 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_that_s(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

// Goes through the list.
static char	*go_through_file(int fd)
{
    char    *buffer;
	ssize_t	check;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	check = read(fd, buffer, BUFFER_SIZE);
	if (check <= 0)
		return (free(buffer), NULL);
	buffer[check] = '\0';
	return (buffer);
}

// Splits the last buffer into two and gives it to linked_list_time.
static char	*cut_buffer(char **line)
{
	char		*last_part;
	size_t		len;
	size_t		index;

	len = 0;
	index = 0;
	while ((*line)[len] != '\n')
		len++;
	len++;
	last_part = malloc(len + 1);
	if (!last_part)
		return (NULL);
	len++;
	while ((*line)[len + index] != '\0')
	{
		last_part[index] = (*line)[len + index];
		(*line)[len + index] = '\0';
		index++;
	}
	return (last_part);
}

// Does get_next_line stuff.
char	*get_next_line(int fd)
{
	static char	*buffer;
	char	    *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	while (1)
	{
		if (buffer)
		{
			line = ft_strdup(buffer);
			if (!line)
				return (free_that_s(&buffer), NULL);
			free_that_s(&buffer);
		}
		line = ft_strdup(ft_strjoin(line, go_through_file(fd)));
		if (!line)
			return (NULL);
		if (line && ft_strchr(line, '\n'))
		{
			buffer = ft_strdup(cut_buffer(&line));
			if (!buffer)
				return (NULL);
			break ;
		}
	}
	return (line);
}

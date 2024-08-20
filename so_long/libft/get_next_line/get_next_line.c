/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:14 by bgretic           #+#    #+#             */
/*   Updated: 2024/06/11 16:45:05 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cut_line(const char *line)
{
	char	*buffer;
	size_t	index;

	index = 0;
	while (line[index] != '\n')
		index++;
	index++;
	buffer = malloc(index + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (*line != '\n')
		buffer[index++] = *line++;
	if (*line == '\n')
		buffer[index++] = *line++;
	buffer[index] = '\0';
	return (buffer);
}

static char	*get_stash(const char *line)
{
	char	*last_part;
	size_t	index;

	index = 0;
	line = ft_strchr(line, '\n');
	if ((*line + 1) != '\0')
		line++;
	else
		return (NULL);
	while (line[index] != '\0')
		index++;
	last_part = malloc(index + 1);
	if (!last_part)
		return (NULL);
	index = 0;
	while (*line != '\0')
		last_part[index++] = *line++;
	last_part[index] = '\0';
	return (last_part);
}

static int	first_part(char **stash, char **buffer, char **line)
{
	if (*stash && (**stash) != '\0')
	{
		*line = ft_strdup(*stash);
		if (!*line)
			return (free_that(stash), -1);
	}
	free_that(stash);
	if (*line && ft_strchr(*line, '\n'))
	{
		*stash = get_stash(*line);
		if (!*stash)
			return (free_that(line), -1);
		*buffer = cut_line(*line);
		free_that(line);
		*line = ft_strdup(*buffer);
		if (!*line)
			return (free_that(stash), free_that(buffer), -1);
		free_that(buffer);
		return (1);
	}
	return (0);
}

static int	second_part(int fd, char **stash, char **buffer, char **line)
{
	*buffer = go_through_file(fd, line);
	if (!*buffer && *line)
		return (1);
	else if (!*buffer && !*line)
		return (-1);
	if (*line)
	{
		*stash = ft_strdup(*line);
		if (!*stash)
			return (free_that(buffer), free_that(line), -1);
		free_that(line);
		*line = ft_strjoin(*stash, *buffer);
		if (!*line)
			return (free_that(buffer), free_that(stash), -1);
	}
	else
	{
		*line = ft_strdup(*buffer);
		if (!*line)
			return (free_that(buffer), -1);
	}
	free_that(buffer);
	free_that(stash);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			check;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_that(&stash), NULL);
	line = NULL;
	check = 0;
	while (1)
	{
		check = first_part(&stash, &buffer, &line);
		if (check == 1)
			break ;
		else if (check == -1)
			return (NULL);
		check = second_part(fd, &stash, &buffer, &line);
		if (check == 1)
			break ;
		else if (check == -1)
			return (NULL);
	}
	return (line);
}

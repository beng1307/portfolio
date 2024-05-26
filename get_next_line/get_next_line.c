/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:14 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/26 18:12:19 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Goes through the list.
static char	*go_through_file(int fd)
{
    char    *buffer;
	char	*temp;
	ssize_t	check;
	size_t index;

	index = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	check = read(fd, temp, BUFFER_SIZE);
	if (check <= 0)
		return (free_that(&temp), NULL);
	temp[check] = '\0';
	buffer = malloc(check + 1);
	if (!buffer)
		return (NULL);
	while (temp[index] != '\0')
	{
		buffer[index] = temp[index];
		index++;
	}
	buffer[index] = '\0';
	free_that(&temp);
	return (buffer);
}

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

// Does get_next_line stuff.
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char	    *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (stash)
		{
			line = ft_strdup(stash);
			if (!line)
				return (free_that(&stash), NULL);
			free_that(&stash);
		}
		if (!ft_strchr(stash, '\n'))
		buffer = go_through_file(fd);
		if (!buffer && line)
			break ;
		else if (!buffer && !line)
			return (NULL);
		if (line)
		{
			stash = ft_strdup(line);
			if (!stash)
				return (free_that(&buffer), free_that(&line), NULL);
			free_that(&line);
			line = ft_strjoin(stash, buffer);
			if (!line)
				return (free_that(&buffer), free_that(&stash), NULL);
		}
		else
		{
			line = ft_strdup(buffer);
			if (!line)
				return (free_that(&buffer), NULL);
		}
		free_that(&buffer);
		free_that(&stash);
		if (line && ft_strchr(line, '\n'))
		{
			stash = get_stash(line);
			if (!stash)
				return (free_that(&line), NULL);
			buffer = cut_line(line);
			free_that(&line);
			line = ft_strdup(buffer);
			free_that(&buffer);
			break ;
		}
	}
	return (line);
}

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
		return (free_that(buffer), NULL);
	buffer[check] = '\0';
	return (buffer);
}

// Splits the last buffer into two and gives it to linked_list_time.
static void	cut_line(char **line)
{
	size_t	index;

	index = 0;
	while ((*line)[index] != '\n')
		index++;
	index++;
	while ((*line)[index] != '\0')
		(*line)[index++] == '\0';
}

static char	*get_stash(const char *line)
{
	char	*last_part;
	size_t	index;

	index = 0;
	line = ft_strchr(line, '\n');
	if ((line + 1) != '\0')
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
	while (1)
	{
		if (stash)
		{
			line = ft_strdup(stash);
			if (!line)
				return (free_that(stash), free_that(line), NULL);
			free_that(stash);
		}
		buffer = go_through_file(fd);
		if (!buffer)
			return (NULL);
		if (line)
		{
			stash = ft_strdup(line);
			if (!stash)
				return (free_that(buffer), NULL);
		}
		line = ft_strjoin(stash, buffer);
		if (!line)
			return (free_that(buffer, stash), NULL);
		free_that(buffer, stash);
		if (line && ft_strchr(line, '\n'))
		{
			stash = get_stash(line);
			if (!stash)
				return (free_that(line), NULL);
			cut_line(&line);
			break ;
		}
	}
	return (NULL);
}

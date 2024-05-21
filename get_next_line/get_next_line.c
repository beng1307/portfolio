/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:14 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/21 19:10:15 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Goes through the list.
static char	*go_through_file(int fd)
{
    char    *buffer_first;
	char	*buffer_second;
	ssize_t	check;

	buffer_first = malloc(BUFFER_SIZE + 1);
	if (!buffer_first)
		return (NULL);
	check = read(fd, buffer_first, BUFFER_SIZE);
	if (!(check > 0))
		return (free(buffer_first), NULL);
	buffer_first[check + 1] = '\0';
	buffer_second = ft_strdup(buffer_first);
	if (!buffer_second)
		return (NULL);
	return (free(buffer_first), buffer_second);
}

// Splits the last buffer into two and gives it to linked_list_time.
static char	*cut_buffer(char *buffer)
{
	char	*first_part;
	size_t	len;

	len = 0;
	while (buffer[len] != '\n')
		len++;
	len++;
	first_part = malloc(len + 1);
	if (!first_part)
		return (NULL);
	first_part[len + 1] = '\0';
	len = 0;
	while (*(buffer - 1) != '\n')
		(first_part)[len++] = *buffer++;
	return (first_part);
}

// Does get_next_line stuff.
char	*get_next_line(int fd)
{
	size_t      check;
	char	    *line;
	static char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	check = 1;
	line = malloc(1);
	if (!line)
		return (NULL);
	while (check > 0)
	{
		buffer = go_through_file(fd);
		if (!buffer)
			return (NULL);
		if (*buffer && ft_strchr(buffer, '\n') == 0)
			line = ft_strjoin(line, buffer);
		else if (*buffer && ft_strchr(buffer, '\n'))
			return (line = ft_strjoin(line, cut_buffer(buffer)));
	}
	return (line);
}

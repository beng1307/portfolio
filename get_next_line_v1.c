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
		return (free(buffer), NULL);
	buffer[check] = '\0';
	return (buffer);
}

// Splits the last buffer into two and gives it to linked_list_time.
static char	*cut_buffer(char **buffer)
{
	char	*first_part;
	size_t	len;

	len = 0;
	while ((*buffer)[len] != '\n')
		len++;
	len++;
	first_part = malloc(len + 1);
	if (!first_part)
		return (NULL);
	ft_strlcpy(first_part, *buffer, len + 1);
	*buffer += len;
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
		if (buffer && ft_strchr(buffer, '\n') == 0)
			line = ft_strjoin(line, buffer);
		else if (buffer && ft_strchr(buffer, '\n'))
			return (line = ft_strjoin(line, cut_buffer(&buffer)));
		buffer = go_through_file(fd);
		if (!buffer && read(fd, buffer, BUFFER_SIZE) > 0)
			return (NULL);
		else if (!buffer && read(fd, buffer, BUFFER_SIZE) <= 0)
			return (line);
	}
	return (line);
}
#include "get_next_line.h"

char *ft_strdup(char *line)
{
	char	*str;
	int 	index = 0;

	while (line[index])
		index++;
	str = malloc(index + 1);
	index = 0;
	while (line[index])
	{
		str[index] = line[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	bytes_read;
	static int	buffer_index;
	int 		index = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read <= 0)
				break;
		}
		if (buffer[buffer_index] == '\n')
			break;
		line[index] = buffer[buffer_index++];
		index++;
	}
	line[buffer_index] = '\0';
	if (buffer_index == 0)
		return (NULL);
	return (ft_strdup(line));
}

#include "so_long.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static char	**parse_map(char *file_name)
{
	char	**map;
	char	*line;
	int		file;
	int		index;


	file = open("file_name", O_RDONLY);
	if (!file)
		return (perror("open"), NULL);
	index = 0;
	line = get_next_line(file);
	if (!line)
		return (ft_putendl_fd("File was empty!", 2), NULL);
	while (line)
	{
		map[index++] = line;
		line = get_next_line(fd);
	}
	return (map);
}

static void	is_rectangular(char **map)
{

}

char	**check_map(char *file_name)
{
	char	**map;

	map = parse_map(file_name);
	is_rectangular(*map);
}

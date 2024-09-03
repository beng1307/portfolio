#include "so_long.h"

static void	remove_newline(char **map)
{
	int		line;
	int		column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column] && map[line][column] != '\n')
			column++;
		if (map[line][column] == '\n')
			map[line][column] = '\0';
		line++;
	}
}

char	**parse_map(char *file_name)
{
	char	**map;
	char	*line;
	int		file;
	int		index;

	map = malloc(32 * sizeof(char *));
	if (!map)
		return (perror("malloc"), NULL);
	file = open(file_name, O_RDONLY);
	if (!file)
		return (perror("open"), NULL);
	index = 0;
	line = get_next_line(file);
	if (!line)
		return (ft_putendl_fd("File was empty!", 2), NULL);
	while (line)
	{
		map[index++] = line;
		line = get_next_line(file);
	}
	map[index] = NULL;
	remove_newline(map);
	return (map);
}

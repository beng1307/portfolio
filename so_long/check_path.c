#include "so_long.h"

bool	check_path(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		return (true);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (false);
	map[y][x] = 'X';
	if (check_path(map, y - 1, x))
		return (true);
	if (check_path(map, y + 1, x))
		return (true);
	if (check_path(map, y, x - 1))
		return (true);
	if (check_path(map, y, x + 1))
		return (true);
	return (false);
}
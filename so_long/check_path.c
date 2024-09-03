#include "so_long.h"

// static bool	are_collectibles_left(char **map)
// {
// 	int	line;
// 	int	column;

// 	line = 0;
// 	while (map[line])
// 	{
// 		column = 0;
// 		while (map[line][column])
// 		{
// 			if (map[line][column] == 'C')
// 				return (true);
// 			column++;
// 		}
// 		line++;
// 	}
// 	return (false);
// }

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

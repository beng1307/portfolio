#include "so_long.h"

static void	check_top_and_bottom_wall(char **map)
{
	int	column_index;
	int	last_line;

	column_index = 0;
	last_line = ft_linelen(map);
	while (map[0][column_index] && map[last_line][column_index])
	{
		if (!ft_strchr("1", map[0][column_index])
			|| !ft_strchr("1", map[last_line][column_index++]))
		{
			free_that(map);
			fr_putendl_fd("Error", 2);
			ft_putstr_fd("The Wall is not alright!", 2);
			exit(-1);
		}
	}
}

static void check_walls_in_between(char **map)
{
	int	line_index;
	int	last_column;

	line_index = 1;
	last_column = ft_strlen(map[0]);
	while (map[line_index + 1])
	{
		if (map[line_index][0] != '1' || map[line_index][last_column] != '1')
		{
			free_that(map);
			fr_putendl_fd("Error", 2);
			ft_putstr_fd("The Wall is not alright!", 2);
			exit(-1);
		}
		line_index++;
	}
}

void	check_walls(char **map)
{
	check_top_and_bottom_wall(map);
	check_walls_in_between(map);
}

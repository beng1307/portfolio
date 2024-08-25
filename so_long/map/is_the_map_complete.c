#include "push_swap.h"

static int	*count_map_content(char **map, int line_index, int column_index)
{
	static int	starting_points = 0;
	static int	exit_points = 0;
	static int	collectibles = 0;
	static int	empty_spaces = 0;
	static int	array[4]; 

	if (ft_strchr("P", map[line_index][column_index]))
		starting_points++;
	else if (ft_strchr("E", map[line_index][column_index]))
		exit_points++;
	else if (ft_strchr("C", map[line_index][column_index]))
		collectibles++;
	else if (ft_strchr("0", map[line_index][column_index]))
		empty_spaces++;
	array[0] = starting_points;
	array[1] = exit_points;
	array[2] = collectibles;
	array[3] = empty_spaces;
	return (array);
}

void	is_the_map_complete(char **map)
{
	int	line_index;
	int	column_index;
	int	*map_content;

	line_index = 0;
	column_index = 0;
	while (map[line_index])
	{
		while (map[line_index][column_index])
			map_content = count_map_content(map, line_index, column_index++);
		column_index = 0;
		line_index++;
	}
	if (map_content[0] != 1 || map_content[1] != 1
		|| map_content[2] == 0 || map_content[3] == 0)
	{
		free_that(map);
		fr_putendl_fd("Error", 2);
		ft_putstr_fd("The Map is not compliant with the requirements!", 2);
		exit(-1);		
	}
}


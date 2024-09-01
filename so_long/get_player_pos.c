#include "so_long.h"

void get_player_pos(t_mlx **game)
{
	int line;
	int	column;

	line = 0;
	column = 0;
	(*game)->moves = 0;
	(*game)->collected = false;
	while (game[line])
	{
		while (game[line][column])
		{
			if (game[line][column] == 'P')
			{
				(*game)->p_pos->y = line;
				(*game)->p_pos->x = column;
				return ;
			}
			column++;
		}
		column = 0;
		line++;
	}
}
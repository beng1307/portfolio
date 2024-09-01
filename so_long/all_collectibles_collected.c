#include "so_long"

void	all_collectibles_collected(t_mlx **game)
{
	int	line;
	int	column;

	if ((*game)->collected)
		return ;
	line = 0;
	column = 0;
	while (game->map[line])
	{
		while (game->map[line][column])
		{
			if (game->map[line][column] == 'C')
				return ;
			column++;
		}
		column = 0;
		line++;
	}
	(*game)->collected = true;
}
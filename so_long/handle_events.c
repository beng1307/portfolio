#include "so_long.h"

static int	handle_keys(int key, t_mlx **game)
{
	if (key == UP)
		move_up(game);
	else if (key == DOWN)
		move_down(game);
	else if (key == LEFT)
		move_left(game);
	else if (key == RIGHT)
		move_right(game);
	else if(key == ESCAPE)
		exit_game(game, NULL);
	return (0);
}

void	handle_events(t_mlx **game)
{
	all_collectibles_collected(game);
	open_door(game);
	mlx_key_hook((*game)->win, handle_keys, game);
}

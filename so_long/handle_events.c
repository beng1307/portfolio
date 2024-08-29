#include "so_long.h"

static void	handle_keys(int key, t_mlx **game)
{
	if (key == UP)
		move_up(mlx);
	else if (key == DOWN)
		move_down(mlx);
	else if (key == LEFT)
		move_left(mlx);
	else if (key == RIGHT)
		move_right(mlx);
	else if(key == ESCAPE);
		exit_game(mlx);
}

void	handle_events(t_mlx **game)
{
	mlx_key_hook(mlx->pwin, handle_keys, mlx);
}
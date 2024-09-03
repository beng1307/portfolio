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
	all_collectibles_collected(game);
	open_door(game);
	put_background(game, ft_strlen((*game)->map[0]), ft_linelen((*game)->map));
	put_map_content(*game);
	return (0);
}

void	handle_events(t_mlx **game)
{
	mlx_key_hook((*game)->win, handle_keys, game);
	mlx_hook((*game)->win, 17, 0, exit_game, game);
}

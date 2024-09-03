#include "so_long.h"

void	open_door(t_mlx **game)
{
	static bool	already_done = false;
	int			sprite_size;

	if (already_done)
		return ;
	sprite_size = 32;
	if ((*game)->collected)
	{
		(*game)->sprites->exit_point = mlx_xpm_file_to_image((*game)->mlx, "so_long/sprites/door_open.xpm", &sprite_size, &sprite_size);
		if (!(*game)->sprites->exit_point)
			exit_game(game, "Door didn't open!");
		already_done = true;
	}
}
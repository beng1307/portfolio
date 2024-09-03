#include "so_long.h"

void	init_mlx(t_mlx **game)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		exit_game(game, "Mlx initialisation failed!");
}

void	init_window(t_mlx **game)
{
	int		width;
	int		height;

	width = ft_strlen((*game)->map[0]) * 32;
	height = ft_linelen((*game)->map) * 32;
	(*game)->win = mlx_new_window((*game)->mlx, width, height, "So_Long");
	if (!(*game)->win)
		exit_game(game, "Window initalisation failed!");
}
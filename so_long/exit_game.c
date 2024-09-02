#include "so_long.h"

static void	free_sprites(void *mlx, t_assets **sprites)
{
	if ((*sprites)->player)
	{
		mlx_destroy_image(mlx, (*sprites)->player);
		(*sprites)->player = NULL;
	}
	if ((*sprites)->exit_point)
	{
		mlx_destroy_image(mlx, (*sprites)->exit_point);
		(*sprites)->exit_point = NULL;
	}
	if ((*sprites)->collectibles)
	{
		mlx_destroy_image(mlx, (*sprites)->collectibles);
		(*sprites)->collectibles = NULL;
	}
	if ((*sprites)->empty_spaces)
	{
		mlx_destroy_image(mlx, (*sprites)->empty_spaces);
		(*sprites)->empty_spaces = NULL;
	}
	if ((*sprites)->walls)
	{
		mlx_destroy_image(mlx, (*sprites)->walls);
		(*sprites)->walls = NULL;
	}
}

static void	free_game(t_mlx **game)
{
	if ((*game)->map)
		free_str_arr(&(*game)->map);
	if ((*game)->sprites)
	{
		free_sprites();
		free((*game)->sprites);
		(*game)->sprites = NULL;
	}
	if ((*game)->win)
		mlx_destroy_window((*game)->mlx, (*game)->win);
	if ((*game)->mlx)
	{
		mlx_destroy_mlx((*game)->mlx);
		free((*game)->mlx);
	}
	free(*game);
	*game = NULL;
}

void	exit_game(t_mlx **game, char *message)
{
	free_game(game);
	if (message)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd(message, 2);
		exit (1);
	}
	else
		exit (0);
}
#include "so_long.h"

static void	free_sprites(assets *sprites)
{
	if (sprites->start_point)
		free_that(&sprites->start_point);
	if (sprites->exit_point)
		free_that(&sprites->exit_point);
	if (sprites->collectibles)
		free_that(&sprites->collectibles);
	if (sprites->empty_spaces)
		free_that(&sprites->empty_spaces);
	if (sprites->walls)
		free_that(&sprites->walls);
	free_that(&sprites);
}

assets	*init_sprites(void *mlx, char **map)
{
	assets	*sprites;
	int		sprite_size;

	sprites = malloc(sizeof(assets));
	if (!sprites)
		return (NULL);
	sprite_size = 32;
	sprites->start_point = mlx_xpm_file_to_image(mlx, "sprites/.xpm", &sprite_size, &sprite_size);
	sprites->exit_point = mlx_xpm_file_to_image(mlx, "sprites/downstairs.xpm", &sprite_size, &sprite_size);
	sprites->collectibles = mlx_xpm_file_to_image(mlx, "sprites/chest_closed.xpm", &sprite_size, &sprite_size);
	sprites->empty_spaces = mlx_xpm_file_to_image(mlx, "sprites/dark_ground.xpm", &sprite_size, &sprite_size);
	sprites->walls = mlx_xpm_file_to_image(mlx, "sprites/walls.xpm", &sprite_size, &sprite_size);
	if (!sprites->start_point || !sprites->exit_point || !sprites->collectibles
		|| !sprites->empty_spaces || !sprites->walls)
		return (free_sprites(sprites), NULL);
	return (sprites);
}
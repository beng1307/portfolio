/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:39:56 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/26 18:01:28 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_sprites(void *mlx, assets *sprites)
{
	if (sprites->player)
		mlx_destroy_image(mlx, sprites->player);
	if (sprites->exit_point)
		mlx_destroy_image(mlx, sprites->exit_point);
	if (sprites->collectibles)
		mlx_destroy_image(mlx, sprites->collectibles);
	if (sprites->empty_spaces)
		mlx_destroy_image(mlx, sprites->empty_spaces);
	if (sprites->walls)
		mlx_destroy_image(mlx, sprites->walls);
	free(sprites);
}

assets	*init_sprites(void *mlx, char **map)
{
	assets	*sprites;
	int		sprite_size;

	sprites = malloc(sizeof(assets));
	if (!sprites)
		return (NULL);
	sprite_size = 32;
	sprites->player = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &sprite_size, &sprite_size);
	sprites->exit_point = mlx_xpm_file_to_image(mlx, "sprites/downstairs.xpm", &sprite_size, &sprite_size);
	sprites->collectibles = mlx_xpm_file_to_image(mlx, "sprites/chest_closed.xpm", &sprite_size, &sprite_size);
	sprites->empty_spaces = mlx_xpm_file_to_image(mlx, "sprites/dark_ground.xpm", &sprite_size, &sprite_size);
	sprites->walls = mlx_xpm_file_to_image(mlx, "sprites/walls.xpm", &sprite_size, &sprite_size);
	if (!sprites->player || !sprites->exit_point || !sprites->collectibles
		|| !sprites->empty_spaces || !sprites->walls)
		return (free_sprites(mlx, sprites), free_that(map), NULL);
	return (sprites);
}
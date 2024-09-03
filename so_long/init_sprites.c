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

void	init_sprites(t_mlx **game)
{
	int	sprite_size;

	sprite_size = 32;
	(*game)->sprites = malloc(sizeof(t_assets));
	if (!(*game)->sprites)
		exit_game(game, "Sprites couldn't get allocated!");
	(*game)->sprites->player = mlx_xpm_file_to_image((*game)->mlx, "so_long/sprites/player.xpm", &sprite_size, &sprite_size);
	(*game)->sprites->exit_point = mlx_xpm_file_to_image((*game)->mlx, "so_long/sprites/door_closed.xpm", &sprite_size, &sprite_size);
	(*game)->sprites->collectibles = mlx_xpm_file_to_image((*game)->mlx, "so_long/sprites/chest_closed.xpm", &sprite_size, &sprite_size);
	(*game)->sprites->empty_spaces = mlx_xpm_file_to_image((*game)->mlx, "so_long/sprites/dark_ground.xpm", &sprite_size, &sprite_size);
	(*game)->sprites->walls = mlx_xpm_file_to_image((*game)->mlx, "so_long/sprites/wall.xpm", &sprite_size, &sprite_size);
	if (!(*game)->sprites->player || !(*game)->sprites->exit_point || !(*game)->sprites->collectibles
		|| !(*game)->sprites->empty_spaces || !(*game)->sprites->walls)
		exit_game(game, "Sprite initialisation failed!");
}
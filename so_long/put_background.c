/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:29 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/26 17:28:49 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_mlx **game, int win_width, int win_height)
{	
	// void	*background;
	// int		sprite_size;
	int		y_coord;
	int		x_coord;

	// sprite_size = 32;
	y_coord = 0;
	x_coord = 0;
	// background = mlx_xpm_file_to_image((*game)->mlx, "so_long/sprites/dark_ground.xpm", &sprite_size, &sprite_size);
	// if (!background)
	// 	exit_game(game, "Couldn't initialise background!");
	while (y_coord != win_height)
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->sprites->empty_spaces, x_coord * 32, y_coord * 32);
		x_coord++;
		if (x_coord == win_width)
		{
			x_coord = 0;
			y_coord++;
		}
	}
}

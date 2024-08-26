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

void	put_background(void *mlx, void *window, int win_width, int win_height)
{	
	void	*background;
	int		sprite_size;
	int		y_coord;
	int		x_coord;

	sprite_size = 160;
	y_coord = 0;
	x_coord = 0;
	background = mlx_xpm_file_to_image(mlx, "sprites/grass.xpm", &sprite_size, &sprite_size);
	while (y_coord != win_height)
	{
		mlx_put_image_to_window(mlx, window, background, y_coord, x_coord);
		x_coord += sprite_size;
		if (x_coord == win_width)
		{
			x_coord = 0;
			y_coord += sprite_size;
		}
	}
}

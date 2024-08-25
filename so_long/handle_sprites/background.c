/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:29 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/21 11:50:04 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(void *mlx, void *window)
{	
	void	*background;
	int		sprite_size;
	int		y_coord;
	int		x_coord;

	sprite_size = 160;
	y_coord = 0;
	x_coord = 0;
	background = mlx_xpm_file_to_image(mlx, "sprites/grass.xpm", &sprite_size, &sprite_size);
	while (y_coord != WIN_HEIGHT)
	{
		mlx_put_image_to_window(mlx, window, background, y_coord, x_coord);
		x_coord += sprite_size;
		if (x_coord == WIN_WIDTH)
		{
			x_coord = 0;
			y_coord += sprite_size;
		}
	}
}

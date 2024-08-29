/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:39:43 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/26 15:39:44 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map_content(t_mlx *game)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	while (map[line])
	{
		while (map[line][column])
		{
			if (map[line][column] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->empty_spaces, line * 32, column * 32);
			else if (map[line][column] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->walls, line * 32, column * 32);
			else if (map[line][column] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->collectibles, line * 32, column * 32);
			else if (map[line][column] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->exit_point, line * 32, column * 32);
			else if (map[line][column] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->player, line * 32, column * 32);
			column++;
		}
		column = 0;
		line++;
	}
}

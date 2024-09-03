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
	while (game->map[line])
	{
		while (game->map[line][column])
		{
			if (game->map[line][column] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->empty_spaces, column * 32, line * 32);
			else if (game->map[line][column] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->walls, column * 32, line * 32);
			else if (game->map[line][column] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->collectibles, column * 32, line * 32);
			else if (game->map[line][column] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->exit_point, column * 32, line * 32);
			else if (game->map[line][column] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites->player, column * 32, line * 32);
			column++;
		}
		column = 0;
		line++;
	}
}

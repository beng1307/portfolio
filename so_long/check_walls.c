/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:39:52 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/26 17:49:01 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_top_and_bottom_wall(t_mlx **game)
{
	int	column_index;
	int	last_line;

	column_index = 0;
	last_line = ft_linelen((*game)->map);
	while ((*game)->map[0][column_index] && (*game)->map[last_line][column_index])
	{
		if (!ft_strchr("1", (*game)->map[0][column_index])
			|| !ft_strchr("1", (*game)->map[last_line][column_index++]))
			exit_game(game, "Walls are not ok!");
	}
}

static void check_walls_in_between(t_mlx **game)
{
	int	line_index;
	int	last_column;

	line_index = 1;
	last_column = ft_strlen((*game)->map[0]);
	while ((*game)->map[line_index + 1])
	{
		if ((*game)->map[line_index][0] != '1' || (*game)->map[line_index][last_column] != '1')
			exit_game(game, "Walls are not ok!");
		line_index++;
	}
}

void	check_walls(t_mlx **game)
{
	check_top_and_bottom_wall(game);
	check_walls_in_between(game);
}

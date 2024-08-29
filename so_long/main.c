/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:51 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/26 17:28:25 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx		*game;

	if (ac != 2)
		return (ft_printf("Write the right amount of arguments!"), -1);
	game = (t_mlx *)malloc(sizeof(t_mlx));
	if (!game)
		return (perror(malloc), 1);
	parse_and_check_map(av[1], &game);
	init_mlx(&game);
	init_window(&game);
	init_sprites(game->mlx, game->map);
	put_background(&game, ft_strlen((*game)->map[0]), ft_linelen((*game)->map));
	put_map_content(game);
	handle_events(&game);
	mlx_loop(&game);
	exit_game(&game, NULL);
}

//floodfill

/*
TODO

I changed the t_mlx mlx into game
and the sprites are not in the game struct.
Change it everywhere else!

Also create a function for moving and for closing/freeing everything.
*/

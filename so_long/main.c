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

static void	*init_window(void *mlx, char **map)
{
	void	*window;

	window = mlx_new_window(mlx, ft_strlen(*map), ft_linelen(map), "So_Long");
	if (!window)
	{
		free(mlx);
		perror("mlx_new_window");
		exit(1);
	}
	return (window);
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;
	t_assets	*sprites;
	char		**map;

	if (ac != 2)
		return (ft_printf("Write the right amount of arguments!"), -1);
	map = parse_and_check_map(av[1]);
	mlx->pmlx = mlx_init();
	if (!mlx_content)
		return (perror("mlx_init"), 1);
	sprites = init_sprites(mlx, map);
	if (!sprites)
		exit(1);
	mlx->pwin = init_window(mlx, map);
	if (!mlx_contnet->win)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd("Window initialization failed!", 2);
		return (mlx_destroy_display(mlx), free(mlx), 1);
	}
	put_background(mlx, window, ft_strlen(map[0]), ft_linelen(map));
	put_map_content(mlx, window, map, sprites);
	handle_events(mlx, window, map);
	mlx_loop(mlx);
}

//floodfill

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:51 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/21 11:42:52 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*init_window(void *mlx)
{
	void	*window;

	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "So_Long");
	if (!window)
	{
		free(mlx);
		perror("mlx_new_window");
		exit(-1);
	}
	return (window);
}

int	main(int ac, char **av)
{
	assets	*sprites;
	void	*mlx;
	void	*window;
	char	**map;

	if (ac != 2)
		return (ft_printf("Write the right amount of arguments!"), -1);
	map = parse_and_check_map(av[1]);
	mlx = mlx_init();
	if (!mlx)
		return (perror("mlx_init"), -1);
	sprites = init_sprites(mlx, map);
	if (!sprites)
		exit(-1);
	window = init_window(mlx);
	if (!window)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd("Window initialization failed!", 2);
		return (mlx_destroy_display(mlx), free(mlx), -1);
	}
	put_background(mlx, window);
	put_map_content(mlx, window, map);
}

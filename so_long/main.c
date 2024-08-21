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

	window = mlx_new_window(mlx, 800, 600, "So_Long");
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
	void	*mlx;
	void	*window;
	char	**map;

	if (ac != 2)
		return (ft_printf("Write the right amount of arguments!"), -1);
	map = check_and_parse_map(av[1]);
	mlx = mlx_init();
	if (!mlx)
		return (perror("mlx_init"), -1);
	window = init_window(mlx);
	init_images(mlx, window, map);
	sleep(10);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:43:01 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/26 17:27:13 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include <fcntl.h>
#include <errno.h>
#include <mlx.h>
#include <stdio.h>
#include <stdbool.h>
#include <X11/keysym.h>

#define UP 76
#define DOWN 80
#define LEFT 75
#define RIGHT 77


typedef struct s_assets
{
	void	*player;
	void	*exit_point;
	void	*collectibles;
	void	*empty_spaces;
	void	*walls;
}			t_assets;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;



assets	*init_sprites(void *mlx, char **map);

void	is_the_map_content_correct(char **map);

void	is_the_map_complete(char **map);

void	check_walls(char **map);

char	**parse_and_check_map(char *file_name);



void	put_background(void *mlx, void *window, int win_width, int win_height);

void	put_map_content(void *mlx, void *win, char **map, assets *sprites);

#endif
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
#define	ESCAPE 53


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
	void		*mlx;
	void		*win;
	char		**map;
	t_assets 	*sprites;
}				t_mlx;


char		**parse_and_check_map(char *file_name, t_mlx **game);

void		is_the_map_complete(t_mlx **game);

void		check_walls(t_mlx **game);

void		exit_game(t_mlx **game, char *message);

void		init_mlx(t_mlx **game);

void		init_window(t_mlx **game);

t_assets	init_sprites(t_mlx **game);

void		put_background(t_mlx **game, int win_width, int win_height);

void		put_map_content(t_mlx *game);

void		handle_events(t_mlx **game);



#endif
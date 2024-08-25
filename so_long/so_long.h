/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:43:01 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/21 11:43:02 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIN_WIDTH 800
#define	WIN_HEIGHT 640

#include "libft/libft.h"
#include <fcntl.h>
#include <errno.h>
#include <mlx.h>
#include <stdio.h>

typedef struct asset_list
{
	void	*start_point;
	void	*exit_point;
	void	*collectibles;
	void	*empty_spaces;
	void	*walls;
} assets;

void	is_the_map_content_correct(char **map);

void	is_the_map_complete(char **map);

void	check_walls(char **map);

char	**parse_and_check_map(char *file_name);


void	put_background(void *mlx, void *window);


#endif
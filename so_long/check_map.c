/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:44 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/21 12:51:27 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static char	**parse_map(char *file_name)
{
	char	**map;
	char	*line;
	int		file;
	int		index;


	file = open("file_name", O_RDONLY);
	if (!file)
		return (perror("open"), NULL);
	index = 0;
	line = get_next_line(file);
	if (!line)
		return (ft_putendl_fd("File was empty!", 2), NULL);
	while (line)
	{
		map[index++] = line;
		line = get_next_line(fd);
	}
	return (map);
}

static void	is_rectangular(char **map)
{
	int	index;
	int	length_first_line;
	int	length_other_lines;

	index = 0;
	length_first_line = ft_strlen(map[index++]);
	while (map[index])
	{
		length_other_lines = ft_strlen(map[index++]);
		if (length_first_line != length_other_lines)
		{
			ft_putendl_fd("Error", 2);
			ft_putstr_fd("The Map is not rectangular!", 2);
			exit(-1);
		}
	}
}

static void	are_the_chars_correct(char **map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		ft_strchr();
		
	}
}

char	**check_and_parse_map(char *file_name)
{
	char	**map;

	map = parse_map(file_name);
	is_rectangular(map);
	are_the_chars_correct(map);
	// is_there_a_path(map);
	return(map);
}

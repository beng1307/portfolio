/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_check_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:44 by bgretic           #+#    #+#             */
/*   Updated: 2024/08/26 17:49:45 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**parse_map(char *file_name)
{
	char	**map;
	char	*line;
	int		file;
	int		index;

	map = NULL;
	file = open(file_name, O_RDONLY);
	if (!file)
		return (perror("open"), NULL);
	index = 0;
	line = get_next_line(file);
	if (!line)
		return (ft_putendl_fd("File was empty!", 2), NULL);
	while (line)
	{
		map[index++] = line;
		line = get_next_line(file);
	}
	return (map);
}

static void	is_the_map_rectangular(char **map)
{
	int	line_index;
	int	length_first_line;
	int	length_other_lines;

	line_index = 0;
	length_first_line = ft_strlen(map[line_index++]);
	while (map[line_index])
	{
		length_other_lines = ft_strlen(map[line_index++]);
		if (length_first_line != length_other_lines)
		{
			free_that(map);
			ft_putendl_fd("Error", 2);
			ft_putstr_fd("The Map is not rectangular!", 2);
			exit(1);
		}
	}
}

void	is_the_map_content_correct(char **map)
{
	int	line_index;
	int	column_index;

	line_index = 0;
	column_index = 0;
	while (map[line_index])
	{
		while (map[line_index][column_index])
		{
			if (!ft_strchr("01CEP", map[line_index][column_index++]))
			{
				free_that(map);
				ft_putendl_fd("Error", 2);
				ft_putstr_fd("The Map has an impostor in it!", 2);
				exit(1);
			}
		}
		line_index++;
	}
}

char	**parse_and_check_map(char *file_name)
{
	char	**map;

	map = parse_map(file_name);
	if (!map)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd("Map parsing failed!", 2);
		exit(1);		
	}
	is_the_map_rectangular(map);
	is_the_map_content_correct(map);
	is_the_map_complete(map);
	check_walls(map);
	// is_there_a_path(map);
	return(map);
}



/*

TODO

* Check if there is a possible way out of the map for the player!

*/


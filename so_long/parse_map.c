/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:46:14 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/11 16:10:52 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	remove_newline(char **map)
{
	int	line;
	int	column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column] && map[line][column] != '\n')
			column++;
		if (map[line][column] == '\n')
			map[line][column] = '\0';
		line++;
	}
}

char	**parse_map(char *file_name)
{
	char	**map;
	char	*line;
	int		file;
	int		index;
	int		error;

	map = ft_calloc(32 * sizeof(char *), 1);
	if (!map)
		return (perror("malloc"), NULL);
	file = open(file_name, O_RDONLY);
	if (!file)
		return (perror("open"), NULL);
	index = 0;
	line = get_next_line(file, &error);
	if (!line)
		return (free_str_arr(&map), NULL);
	while (line)
	{
		map[index++] = line;
		line = get_next_line(file, &error);
		if (error)
			return (free_str_arr(&map), NULL);
	}
	map[index] = NULL;
	remove_newline(map);
	return (map);
}

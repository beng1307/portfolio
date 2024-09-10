/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:51:43 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/10 21:23:09 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*go_through_file(int fd, char **line)
{
	char	*buffer;
	char	*temp;
	ssize_t	check;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_that(line), NULL);
	check = read(fd, temp, BUFFER_SIZE);
	if (check == 0)
		return (free_that(&temp), NULL);
	else if (check == -1)
		return (free_that(&temp), free_that(line), NULL);
	temp[check] = '\0';
	buffer = ft_strdup(temp);
	if (!buffer)
		return (free_that(&temp), free_that(line), NULL);
	free_that(&temp);
	return (buffer);
}

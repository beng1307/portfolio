/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:14 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/16 19:14:48 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Goes through the list.
static char    *go_through_file(int fd)
{
    char    *buffer;
    ssize_t check;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    check = read(fd, buffer, BUFFER_SIZE);
    if (!(check > 0))
        return (free(buffer), NULL);
    return (buffer);
}

//Splits the last buffer into two and gives it to linked_list_time.
static char    *cut_buffer(char *buffer)
{
    char    *first_part;
    size_t  len;

    len = 0;
    while (buffer[len] != '\n')
        len++;
    len++;
    first_part = ft_calloc(len + 1, sizeof(char));
    if (!first_part)
        return (NULL);
    len = 0;
    while (buffer[len - 1] != '\n')
        (first_part)[len++] = *buffer++;
    return (first_part);
}

//Does get_next_line stuff.
char    *get_next_line(int fd)
{
    size_t      check;
    char        *line;
    static char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    check = 1;
    line = malloc(1);
    if (!line)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (check > 0)
    {
        if (*buffer && ft_strchr(buffer, '\n') == 0)
            line = ft_strjoin(line, buffer);
        else if (*buffer && ft_strchr(buffer, '\n'))
        {
            line = ft_strjoin(line, cut_buffer(buffer));
            break;
        }
        buffer = go_through_file(fd);
        if (!buffer)
            return (NULL);
    }
    return (line);
}

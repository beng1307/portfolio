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
char    *go_through_file(int fd)
{
    char    *buffer;
    ssize_t check;

    check = 1;
    while (check > 0)
    {
        buffer = malloc(BUFFER_SIZE + 1);
        check = read(fd, buffer, BUFFER_SIZE);
        if (check > 0)
        {
            buffer[check + 1] = '\0'; 
            if (ft_strchr(buffer, '\n') != 0)
                cut_buffer(buffer);
            else
                linked_list_time(buffer);
        }
        free(buffer);
    }
}

//Splits the last buffer into two and gives it to linked_list_time.
void    cut_buffer(char *buffer)
{
    size_t  index;
    size_t  len;
    char    *buffer_first;
    char    *buffer_second;

    index = 0;
    len = ft_strlen(buffer);
    buffer_first = malloc(len + 1);
    while (*buffer != '\n')
        buffer_first[index++] = (buffer)++;
    if (*buffer == '\n')
        buffer_first[index++] = (buffer)++;
    buffer_first = malloc(index + 1);
    buffer_first[index + 1] = '\0';
    linked_list_time(buffer_first);
    if (*buffer)
    {
        buffer_second = malloc((len - index) + 1);
        index = 0;
        while (*buffer)
            buffer_second[index++] = (buffer)++;
        buffer_second[index + 1] = '\0';
        linked_list_time(buffer_second);
    }
}

//Links the buffers together to get the line.
char    *linked_list_time(char *buffer)
{
    static t_list   *stash;

    if (buffer == NULL)
        return (stash->content, stash = stash->next);
    if (!stash)
        stash = ft_lstnew(buffer);
    strjoin(stash, buffer);

    return (NULL);
}

//Does get_next_line stuff.
char    *get_next_line(int fd)
{
    static size_t   file_listed;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    file_listed = 0;
    if (file_listed == 0)
    {
        go_through_file(fd);
        file_listed = 1;
    }
    else
        line = linked_list_time(NULL);
    return (line);
}

//Notes
//
//I have to check the return values and function types.
//Also let's take a look at my go_through_function.
//And don't forget also to look at the logic and check if it's correct.
//
//Good luck tomorrow Benson, this is peanuts!
//
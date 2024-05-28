/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_line_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:00:12 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/28 20:33:21 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     i;
    int     fd;
    char    *line;

    i = 0;
    fd = open("read_error.txt", O_RDONLY);
    printf("%d", fd);
    while (i < 2)
    {
        line = get_next_line(fd);
        printf("Line: %s\n", line);
        free(line);
        i++;
    }
    i = 0;    
    close (fd);
    fd = open("text.txt", O_RDONLY);
    printf("%d", fd);
    while (i < 2)
    {
        line = get_next_line(fd);
        printf("Line: %s\n", line);
        free(line);
        i++;
    }
    
    close (fd);
}
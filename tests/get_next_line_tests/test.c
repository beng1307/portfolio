/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:00:12 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/30 14:13:57 by bgretic          ###   ########.fr       */
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
    fd = open("text.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s\n", line);
        free_that(line);
        line = get_next_line(fd);
        i++;
    }
    free_that(line);
    close (fd);
}
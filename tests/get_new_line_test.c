/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:00:12 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/27 21:26:23 by bgretic          ###   ########.fr       */
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
    while (i < 22)
    {
        line = get_next_line(fd);
        if (!line)
            return (-1);
        printf("%s", line);
        free_that(&line);
        i++;
    }
    close (fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:00:12 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/29 18:58:53 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     i;
    int     fd1;
    int     fd2;
    int     fd3;
    char    *line;

    i = 0;
    fd1 = open("text1.txt", O_RDONLY);
    fd2 = open("text2.txt", O_RDONLY);
    fd3 = open("text3.txt", O_RDONLY);
    while (i < 6)
    {
        line = get_next_line(fd1);
        printf("Line: %s\n", line);
        line = get_next_line(fd2);
        printf("Line: %s\n", line);
        line = get_next_line(fd3);
        printf("Line: %s\n", line);
        free(line);
        i++;
    }
    i = 0;    
    close (fd1);
    close (fd2);
    close (fd3);
}
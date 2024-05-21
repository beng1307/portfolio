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
    while (i < 5)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
        i++;
    }
    close (fd);
}
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    puts("Test 1");
    fd = open("text.txt", O_RDONLY);
    puts("Test 2");
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close (fd);
}
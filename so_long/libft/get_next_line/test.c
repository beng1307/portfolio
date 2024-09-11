#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        ft_printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    int fd = open(argv[1], O_RDONLY);
    char *str = NULL;
    int error = 0;

    if (fd == -1) {
        perror("open");
        return (1);
    }
    str = get_next_line(fd, &error);
    if (!str && error) {
        return (ft_printf("gnl hat gefailed!\n"), 1);
    }
    ft_printf("%s", str);
    while (str) {
        free(str);
        str = get_next_line(fd, &error);
        if (!str && error) {
            return (ft_printf("gnl hat gefailed!\n"), 1);
        }
        if (str) {
            ft_printf("%s", str);
        }
    }

    close(fd);
    return (0);
}

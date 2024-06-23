#include <unistd.h>

int	main(int ac, char **av)
{
	char *str;

	if (ac == 2)
	{
		str = av[1];
		while (*str == ' ' || *str == '\t')
			str++;
		while (*str && (*str != ' ' && *str != '\t'))
		{
			write(1, &*str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
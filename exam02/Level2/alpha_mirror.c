#include <unistd.h>

int	main(int ac, char **av)
{
	char *str;

	if (ac == 2)
	{
		str = av[1];		
		while (*str)
		{
			if (*str >= 'a' && *str <= 'z')
				*str = 'z' - *str + 'a';
			else if (*str >= 'A' && *str <= 'Z')
				*str = 'Z' - *str + 'A';
			write(1, str++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
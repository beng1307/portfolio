#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		while (*str)
		{
			if (*str >= 'a' && *str <= 'z')
				*str = (*str - 'a' + 13) % 26 + 'a';
			else if (*str >= 'A' && *str <= 'Z')
				*str = (*str - 'a' + 13) % 26 + 'a';
			write(1, &*str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
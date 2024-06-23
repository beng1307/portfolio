#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		while (*str)
		{
			if (*str == '_')
			{
				str++;
				*str -= 32;
			}
			write(1, str++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
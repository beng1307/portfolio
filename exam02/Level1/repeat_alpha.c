#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;
	int		index;
	int		n;

	if (ac == 2)
	{
		str = av[1];
		index = 0;
		while (*str)
		{
			n = 1;
			if (*str >= 'a' && *str <= 'z')
				n = *str - 96;
			else if (*str >= 'A' && *str <= 'Z')
				n = *str - 64;
			while (index < n)
			{
				write(1, &*str, 1);
				index++;
			}
			index = 0;
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
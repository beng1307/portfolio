#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;
	int		check = 0;

	if (ac == 2)
	{
		str = av[1];
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		while (*str)
		{
			if (*str == ' ' || *str == '\t')
				check = 1;
			if (check == 1 && (*str != ' ' || *str == '\t'))
			{
				write(1, "   ", 3);
				check = 0;
			}
			if (*str != ' ' && *str != '\t')
				write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
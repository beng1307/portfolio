#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len])
		str[len++];
	return (len);
}

int	main(int ac, char **av)
{
	char	*to_print;
	char	*to_check;
	int		check = 0;

	if (ac == 3)
	{
		to_print = av[1];
		to_check = av[2];
		while (*to_check)
		{
			if (*to_check == *to_print)
				to_print++;
			if (*to_print == '\0')
			{
				check = 1;
				break ;
			}
			to_check++;
		}
		if (check == 1)
			write(1, av[1], ft_strlen(av[1]));
	}
	write(1, "\n", 1);
}
#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int n = 0;
	int	i = 0;
	int	sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (str[i])
		n = n * 10 + str[i++] - '0';
	return (n * sign);
}

static void	put_digit(int n, int base)
{
	char *str = "0123456789abcdef";

	if (n >= base)
		put_digit(n / base, base);
	write(1, &str[n % base], 1);
}

int main(int ac, char **av)
{
	if (ac == 3)
		put_digit(ft_atoi(av[1]), ft_atoi(av[2]));
	write(1, "\n", 1);
}
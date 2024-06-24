#include <unistd.h>

static void ft_putchar(char c)
{
	write (1, &c, 1);
}

static void ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
}

int	main(void)
{
	int	n;

	n = 1;
	while (n <= 100)
	{
		if (n % 3 == 0)
			write(1, "fizz", 5);
		else if (n % 5 == 0)
			write(1, "buzz", 5);
		else if (n % 15 == 0)
			write (1, "fizzbuzz", 9);
		else
			ft_putnbr(n);
		n++;
		ft_putchar('\n');
	}
	return (0);
}
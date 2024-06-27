#include <unistd.h>

int	miniatoi(char *str)
{
	int num = 0;

	while (*str)
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num);
}

void  miniputnbr(int num)
{
	char *digits = "0123456789";
	
	if (num >= 10)
		miniputnbr(num / 10);
	write(1, &digits[num % 10], 1);
}

int	main(int ac, char **av)
{
	int	index = 1;

	if (ac == 2)
	{
		int num = miniatoi(av[1]);
		while (index <= 9)
		{
			miniputnbr(index);
			write(1, " x ", 3);
			miniputnbr(num);
			write(1, " = ", 3);
			miniputnbr(num * index);
			write(1, "\n", 1);
			index++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
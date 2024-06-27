#include <unistd.h>

int ft_atoi(char *num)
{
	int	number = 0;

	while (*num)
		number = number * 10 + *num++ - '0';
	return (number);
}

void	ft_putnbr(int num)
{
	char	char_num;

	if (num >= 10)
		ft_putnbr(num / 10);
	char_num = num % 10 + '0';
	write(1, &char_num, 1);	
}

int	is_prime(int num)
{
	int	i = 2;

	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	num;
	int sum = 0;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		while (num > 0)
		{
			if (is_prime(num))
				sum += num;
			num--;
		}
		ft_putnbr(sum);
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
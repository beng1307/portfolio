static int ft_miniatoi(char *str)
{
	int	nbr = 0;

	while (*str)
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr);
}

static void	ft_print_hex(int num)
{
	char	hex_digits[] = "0123456789abcdef";

	if (num >= 16)
		print_hex(num / 16);
	write(1, &hex_digits[num % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_print_hex(ft_miniatoi(av[1]));
	write(1, "\n", 1);
}
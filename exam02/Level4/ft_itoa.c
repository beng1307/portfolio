#include <stdlib.h>

char *ft_itoa(int nbr)
{
	char 	*str;
	int		n = nbr;
	int		len = 0;

	if (nbr == -2147483647)
		return ("2147483647\0");
	if (nbr <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

#include <stdio.h>

int main(int ac, char **av)
{
	int 	num;
	char 	*str;

	if (ac == 2)
	{
		num = atoi(av[1]);
		str = ft_itoa(num);
		printf("%s", str);
	}
}

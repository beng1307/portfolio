#include "libft.h"

long int	ft_latoi(const char *str)
{
	long int	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*str && (*str == ' '))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
		if (nbr / 2 > INT_MAX)
			return (nbr * (long)sign);
	}
	return (nbr * (long)sign);
}
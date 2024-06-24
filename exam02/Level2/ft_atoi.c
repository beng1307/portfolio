int	ft_atoi(const char *str)
{
	int	nbr = 0;
	int	sign = 1;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = nbr * 10 + *str - '0';
		str++; 
	}
	return (sign * nbr);
}
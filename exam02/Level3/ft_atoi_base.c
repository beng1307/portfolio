char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int	get_digit(char c, int digits_in_base)
{
	int  max_digits;

	if (digits_in_base <= 10)
		max_digits = digits_in_base + '0';
	else
		max_digits = digits_in_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digits)
		return (c - 'a');	
	else if (c >= 'a' && c <= 'f' && c <= max_digits)
		return (10 + c - 'a');
	else
		return (-1);

}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result = 0;
	int sign = 1;
	int	digit;

	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result *= str_base;
		result += digit * sign;
		str++;
	}
	return (result);
}
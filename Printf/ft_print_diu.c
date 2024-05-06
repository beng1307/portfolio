#include "libft.h"

size_t	ft_print_d(int n)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, &*str, len);
	return (len);
}

size_t	ft_print_u(unsigned int n)
{
	char	*str;
	size_t	len;

	str = ft_utoa(n);
	len = ft_strlen(str);
	write(1, &*str, len);
	return (len);
}

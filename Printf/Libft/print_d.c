#include "libft.h"

void	print_d(int n, size_t to_return)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	to_return += write(1, &*str, len);
}

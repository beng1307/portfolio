#include "libft.h"

void	print_s(char *arg, size_t to_return)
{
	size_t index;

	index = 0;
	while (arg[index] != '\0')
	{
		to_return += write(1, &arg[index], 1);
		index++;
	}
}

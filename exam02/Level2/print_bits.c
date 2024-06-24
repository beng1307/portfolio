#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				index = 8;
	unsigned char	bit;

	while (index--)
	{
		bit = (octet >> index & 1) + '0';
		write(1, &bit, 1);
	}
}
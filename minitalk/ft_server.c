#include "minitalk.h"

static int	decrypt_length(int signum, int length)
{
	if (signum == SIGUSR2)
		length = (length << 1) | 1;
	else if (signum == SIGUSR1)
		length <<= 1;
	return (length);
}

static void	decrypt_content(int signum, int *length, int *length_index)
{
	static char	character = 0;
	static int	bit_index = 0;

	if (signum == SIGUSR2)
		character = (character << 1) | 1;
	else if (signum == SIGUSR1)
		character <<= 1;
	bit_index++;
	if (bit_index == 8)
	{
		ft_putchar_fd(character, 1);
		character = 0;
		bit_index = 0;
		*length -= 1;
		if (!*length)
		{
			ft_putchar_fd('\n', 1);
			*length_index = 0;
		}
	}
}

static void decrypt_message(int signum)
{
	static int	length_index = 0;
	static int	length = 0;

	if (length_index++ < 32)
		length = decrypt_length(signum, length);
	else
		decrypt_content(signum, &length, &length_index);
}

int main(void)
{
	ft_printf("Your process ID is: %d\n\n", getpid());
	while (1)
	{
		signal(SIGUSR1, decrypt_message);
		signal(SIGUSR2, decrypt_message);
	}
}

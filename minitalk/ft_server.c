#include "minitalk.h"

static int	decrypt_length_or_pid(int signum, int to_decrypt)
{
	if (signum == SIGUSR2)
		to_decrypt = (to_decrypt << 1) | 1;
	else if (signum == SIGUSR1)
		to_decrypt <<= 1;
	return (to_decrypt);
}

static void	decrypt_content(int signum, int *length, int *length_index, int pid)
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
			kill(SIGUSR1, pid);
		}
	}
}

static void decrypt_message(int signum)
{
	static int	length_index = 0;
	static int	pid_index = 0;
	static int	length = 0;
	static int	client_pid = 0;

	if (pid_index++ < 32)
		client_pid = decrypt_length_or_pid(signum, client_pid);
	else if (length_index++ < 32)
		length = decrypt_length_or_pid(signum, length);
	else
		decrypt_content(signum, &length, &length_index, client_pid);
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

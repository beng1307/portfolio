#include "minitalk.h"
#include <stdio.h>

static int	decrypt_length(int signum, int length)
{
	if (signum == SIGUSR2)
		length = (length << 1) | 1;
	else if (signum == SIGUSR1)
		length <<= 1;
	return (length);
}

static void	decrypt_content(int signum, int *length, int *len_index, char **msg)
{
	static char	character = 0;
	static int	bit_index = 0;
	static int	msg_index = 0;

	if (signum == SIGUSR2)
		character = (character << 1) | 1;
	else if (signum == SIGUSR1)
		character <<= 1;
	bit_index++;
	if (bit_index == 8)
	{
		(*msg)[msg_index++] = character;
		character = 0;
		bit_index = 0;
		*length -= 1;
		if (!*length)
		{
			ft_putendl_fd(*msg, 1);
			free_that(msg);
			msg_index = 0;
			*len_index = 0;
		}
	}
}

static void decrypt_message(int signum)
{
	static char	*message = NULL;
	static int	length_index = 0;
	static int	length = 0;

	if (length_index++ < 32)
		length = decrypt_length(signum, length);
	else
	{
		if (message == NULL)
			message = ft_calloc(length + 1, sizeof(char));
		decrypt_content(signum, &length, &length_index, &message);
	}
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

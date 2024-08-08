#include "minitalk.h"

static int	check_input(int ac, char **av)
{
	int	index;

	index = 0;
	if (ac != 3)
		return (ft_putendl_fd("Write the right amount of arguments!", 2), -1);
	if (!av[2][index])
		return (ft_putendl_fd("Please write something!", 2), -1);
	if (!av[2])
	while (av[1][index])
	{
		if (!ft_isdigit(av[1][index]))
			return (ft_putendl_fd("Please put only digits in!", 2), -1);
		index++;
	}
	return(0);
}

static void	send_length_or_pid(int server_pid, int to_send)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 32)
	{
		if (((to_send << bit_index) & 2147483648) < 2147483648)
			kill(server_pid, SIGUSR1);
		else if (((to_send << bit_index) & 2147483648) >= 2147483648)
			kill(server_pid, SIGUSR2);
		bit_index++;
		usleep(42);
	}
}

static void send_message(int pid, char *str)
{
	int	bit_index;

	while (*str)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			if (((*str << bit_index) & 128) < 128)
				kill(pid, SIGUSR1);
			else if (((*str << bit_index) & 128) >= 128)
				kill(pid, SIGUSR2);
			bit_index++;
			usleep(42);
		}
		str++;
	}
}

static void	message_received(int signum)
{
	if (signum == SIGUSR1) 
		ft_printf("The server received the message!\n");
}

int	main(int ac, char **av)
{
	int server_pid;
	int	client_pid;
	int	length;

	if (check_input(ac, av) == -1)
		return (-1);
	server_pid = ft_atoi(av[1]);
	client_pid = getpid();
	length = ft_strlen(av[2]);
	send_length_or_pid(server_pid, client_pid);
	send_length_or_pid(server_pid, length);
	send_message(server_pid, av[2]);
	while (1)
		signal(SIGUSR1, message_received);
}


#include "minitalk.h"

static int	check_input(int ac, char **av)
{
	int	index;

	index = 0;
	if (ac != 3)
		return (ft_putendl_fd("Write the right amount of arguments!", 2), -1);
	if (!av[2][index])
		return (ft_putendl_fd("Please write something!", 2), -1);
	while (av[1][index])
	{
		if (!ft_isdigit(av[1][index]))
			return (ft_putendl_fd("Please put only digits in!", 2), -1);
		index++;
	}
	if (ft_latoi(av[1]) > INT_MAX)
		return (ft_putendl_fd("Oh no, i overflow! ..not", 2), -1);
	return(0);
}

static void	send_length(int pid, int length)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 32)
	{
		if (((length << bit_index) & 2147483648) < 2147483648)
			kill(pid, SIGUSR1);
		else if (((length << bit_index) & 2147483648) >= 2147483648)
			kill(pid, SIGUSR2);
		bit_index++;
		usleep(100);
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
			usleep(100);
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	int pid;
	int	length;

	if (check_input(ac, av) == -1)
		return (-1);
	pid = ft_atoi(av[1]);
	length = ft_strlen(av[2]);
	send_length(pid, length);
	send_message(pid, av[2]);
}


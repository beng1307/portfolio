#include "push_swap.h"

void	check_args(int ac, const char **av)
{
	const char	*arg;
	size_t		index;

	index = 1;
	if (ac < 2)
	{
		ft_putendl_fd("Error", 1);
		exit(-1);
	}
	while (av[index])
	{
		arg = av[index++];
		while (*arg)
 		{
			if (!(ft_isdigit(*arg) || *arg == ' ' || *arg == '-')
				|| (*arg == '-' && ft_isdigit(*(arg + 1)) != 1))
			{
				ft_putendl_fd("Error", 1);
				exit(-1);
			}
			arg++;
		}
	}
}

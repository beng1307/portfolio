#include "do_op.h"

int	main(int ac, char **av)
{
	int		arg1;
	int		arg2;
	char	*operator;
	if (ac == 4)
	{
		arg1 = atoi(av[1]);
		arg2 = atoi(av[3]);
		operator = av[2];
		if (*operator == '+')
			printf("%d", arg1 + arg2);
		else if (*operator == '-')
			printf("%d", arg1 - arg2);
		else if (*operator == '*')
			printf("%d", arg1 * arg2);
		else if (*operator == '/')
			printf("%d", arg1 / arg2);
		else if (*operator == '%')
			printf("%d", arg1 % arg2);
	}
	printf("\n");
	return (0);
}
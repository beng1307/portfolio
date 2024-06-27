#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int arg1;
	int arg2;

	if (ac == 3)
	{
		arg1 = atoi(av[1]);
		arg2 = atoi(av[2]);
		if (arg2 > 0 && arg2 > 0)
		{
			while (arg1 != arg2)
			{
				if (arg1 > arg2)
					arg1 -= arg2;
				else
					arg2 -= arg1;
			}
			printf("%d", arg1);
		}
	}
	printf("\n");
	return (0);
}
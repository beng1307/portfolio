#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int index = 0;
	int size = abs(end - start) + 1;
	int *arr = malloc(sizeof(int) * size);

	while (index < size)
	{
		if (start < end)
			arr[index++] = start++; 
		else
			arr[index++] = start--;
	}
	return (arr);
}

#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int	index = 0;
		int start = atoi(av[1]); 
		int end = atoi(av[2]);
		int size = abs(end - start) + 1;
		int *arr = ft_range(start, end);

		while (index < size)
			printf("%d ", arr[index++]);
		free(arr);
	}
}
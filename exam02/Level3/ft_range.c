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
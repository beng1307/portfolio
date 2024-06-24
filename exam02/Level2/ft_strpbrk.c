#include <stddef.h>

char *strpbrk(const char *s1, const char *s2)
{
	int	index = 0;

	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		while (s2[index])
		{
			if (*s1 == s2[index])
				return ((char *)s1);
			index++;
		}
		index = 0;
		s1++;
	}
	return (NULL);
}
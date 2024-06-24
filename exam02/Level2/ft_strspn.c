#include <stddef.h>

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t index = 0;

	while (s[index])
	{
		if (ft_strchr(accept, s[index]) == 0);
			break ;
		index++;
	}
	return (index);
}
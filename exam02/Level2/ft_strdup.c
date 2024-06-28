#include <stddef.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		len = 0;

	while (src[len])
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = 0;
	while (src[len])
	{
		str[len] = src[len];
		len++;
	}
	return (str);
}
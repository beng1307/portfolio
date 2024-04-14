#include <stdlib.h>
#include <stddef.h>

int	ft_strlen(char const *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

static char increment(unsigned int num, char c)
{	
	if (c >= 'a' && c <= 'y')
	{
		c += num;
	}        
	else if (c == 'z')
	{
		c = 'a';
	}
	return (c);
}

static char decrement(unsigned int num, char c)
{

        if (c >= 'b' && c <= 'z')
        {
                c -= num;
        }
        else if (c == 'a')
        {
                c = 'z';
        }
        return (c);
}

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	char		*str;
	unsigned int	i;

	i = 0;
	str = malloc(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char 	*test;

	test = "ggg";
	char *result = ft_strmapi(test, decrement);
	char *result2 = ft_strmapi(test, increment);
	printf("%s\n", result);
	printf("%s\n", result2);
}

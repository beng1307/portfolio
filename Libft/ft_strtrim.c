/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:16:31 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/18 13:50:12 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int	ft_strlen(const char *str)
{
	int	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
	{
		lenght++;
	}
	return (lenght);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*to;
	const char	*from;

	i = 0;
	to = (char *)dest;
	from = (const char *)src;
	while (i < n)
	{
		*to = *from;
		to++;
		from++;
		i++;
	}
	*to = '\0';
	return (dest);
}

static int	ft_strchr(const char *str, const char *c)
{
	while (*c)
	{
		if (*str == *c)
		{
			return (1);
		}
		c++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (ft_strchr(&s1[i], set) == 1)
		i++;
	while (s1[j + 1] != '\0')
		j++;
	while (ft_strchr(&s1[j], set) == 1)
	{
		j--;
		k++;
	}
	str = malloc(ft_strlen(s1) - (k + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, &s1[i], ft_strlen(s1) - (i + k));
	return (str);
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	*test = "lt_himalaja_lt";
	char	*test1 = "iilhgutiw5464";
	char	*test2 = ft_strtrim(test, test1);
	printf("%s\n", ft_strtrim("     \t \n olol", " \t\n"));
	printf("%s\n", ft_strtrim("__05468     lolol 456487 _ "));					
	printf("%s", test2);
}
*/

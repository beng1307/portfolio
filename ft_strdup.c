/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:22:19 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/09 17:21:43 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
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
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = ft_strlen(s) + 1;
	str = malloc(len);
	if (str == NULL)
	{
		return (NULL);
	}
	str = ft_memcpy(str, s, len);
	return ((char *)(str));
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	test[20] = "Hello World";
	char	*test2;

	printf("%p\t%s\n", test, test);
	test2 = ft_strdup(test);
	printf("%p\t%s\n", test2, test2);
	free(test2);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:22:19 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/08 19:13:11 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
	}
	return (count);
}

static size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_lenght;

	i = 0;
	src_lenght = ft_strlen(src);
	if (size == 0)
	{
		return (src_lenght);
	}
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(src_lenght);
}

char	*ft_strdup(const char *s)
{
	const char	*str;

	str = ft_strlcpy(str, s, malloc(ft_strlen(s + 1)));
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	test[20] = "Hello World";
	char	*test2;

	printf("%p\t%s\n", test, test);
	test2 = ft_strdup(test);
	printf("%p\t%s\n", test2);

}

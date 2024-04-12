/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:45:15 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/10 14:40:04 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			j;

	str = malloc(len * sizeof(char));
	i = 0;
	j = 0;
	if ((int)start > ft_strlen(s))
	{
		return (NULL);
	}
	while(i < start - 1)
		i++;
	while(j < len)
	{
		if (s[i + j] == '\0')
		{
			return ((char *)(str));
		}
		str[j] = s[i + j];
		j++;
	}
	return ((char *)(str));
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	*test = "Hello Friene, how are you?";
	char	*test2;

	test2 = ft_substr(test, 7, 7);
	printf("%s", test2);
	free(test2);
}
*/

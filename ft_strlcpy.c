/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:21:59 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/07 15:15:09 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t ft_strlcpy(char *dest, const char *src, size_t size)
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

//test
/*
#include <stdio.h>

int   main(void)
{
    char    test[25] = "Hello";
    char    test2[25] = "Friene";

    printf("%zu\t", ft_strlcpy(test, test2, 4));
    printf("%s", test);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:11:41 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/18 14:20:09 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*terminate;

	i = 0;
	terminate = (char *)s;
	while (i < n)
	{
		*terminate = '\0';
		terminate++;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memp;

	if (nmemb < 1)
		return (NULL);
	if (size == 0)
	{
		memp = malloc(nmemb);
		if (memp == NULL)
			return (NULL);
	}
	else if (nmemb * size <= 2147483647)
	{
		memp = malloc(nmemb * size);
		if (memp == NULL)
			return (NULL);
		ft_bzero(memp, nmemb * size);
	}
	else
		return (NULL);
	return (memp);
}

//test
/*
#include <stdio.h>

int main(void)
{
	char	*test = "Hello World!";

	printf("%p\n", test);
	printf("%s\n", test);
	
	test = ft_calloc(13, sizeof(char));
	
	printf("%p\n", test);
	printf("%s\n", test);
	free(test);
}
*/

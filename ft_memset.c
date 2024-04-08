/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:24:22 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/07 13:50:12 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*set;

	i = 0;
	set = (char *)s;
	while (i < n)
	{
		*set = c;
		set++;
		i++;
	}
	return (s);
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	test[16] = "ITestMyFunction";
	int		i;

	i = 0;
	printf("%s\n", test);
	ft_memset(test, 'x', 7);
	while (i < 16)
	{
		printf("%c", test[i]);
		i++;
	}
}
*/

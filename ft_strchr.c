/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:57:39 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/05 15:00:42 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			return (str);
		}
		str++;
	}
	return 0;
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	test[25] = "Test string!";
	char	*test2 = ft_strchr(test, 'z');

	if (test2 != 0)
	{
		printf("%s", test2);
	}
	else if (test2 == 0)
	{
		printf("The result is NULL");
	}
}
*/

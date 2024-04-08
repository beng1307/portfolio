/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:49:13 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/07 14:11:16 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
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

//test
/*
#include <stdio.h>
int	main(void)
{
	char	test[6] = "Hello";
	char	test2[6];

	ft_memcpy(test2, test, 6);
	printf("%s", test2);
}
*/

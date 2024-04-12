/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:20:45 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/10 12:29:48 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*to;
	const char		*from;

	i = 0;
	to = (char *)dest;
	from = (const char *)src;
	if (to > from)
	{
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	}
	else if (to < from)
	{
		while (n > 0)
		{
			to[n - 1] = from[n - 1];
			n--;
		}
	}
	return (dest);
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	str[20] = "Test Case!";

	ft_memmove(str+5, str, 12);
	printf("%s", str);
	return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:20:45 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/08 10:45:07 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*to;
	char		*from;
	char		temp[n];

	i = 0;
	to = (char *)dest;
	from = (char *)src;
	if (dest == src)
	{
		return (dest);
	}
	else if (dest < src)
	{
		while (i < n)
		{
		}
	}
	else
	{
		while (i < n)
		{	
		}
		while (i > 0)
		{
		}
	}
	return (dest);
}

//test

#include <stdio.h>

int	main(void)
{
	char str[20] = "Moin User!";

	ft_memmove(str+5, str, 12);
	printf("%s", str);
	return 0;
}



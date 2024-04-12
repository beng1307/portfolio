/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:13:48 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/12 20:52:04 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	*ft_numlen(int *n)
{
	int	num;
	int	len;
	int	digit;

	num = n;
	len = 0;
	digit = 0;
	if (num < 0)
	{
		 num = -num;
		 len++;
	}
	while (num >= 10)
	{
		digit = num % 10;
		num -= digit;
		digit = 0;
		len++;
	}
	len += 2;
	return (len);
}

char *ft_itoa(int n)
{
	char	*str;

	str = malloc(ft_numlen(n));
	if (n < 0)
	{
		n = -n;
	}
	while (num >= 10)
	{
		digit = num % 10;
		num -= digit;
		digit = 0;
	}

	return (str);
}

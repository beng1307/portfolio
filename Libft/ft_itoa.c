/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:13:48 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/18 13:46:27 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int n)
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
		digit = num / 10;
		num = digit;
		len++;
	}
	len += 2;
	return (len);
}

static char	ft_strrev(char *str)
{
	char	temp[12];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i] == '-')
	{
		i++;
		j++;
	}
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	while (i > 0 && str[j] != '\0')
	{
		str[j] = temp[i - 1];
		i--;
		j++;
	}
	return (*str);
}

static char	*handle_mmaxint(char *str)
{
	str = "-2147483648";
	return (str);
}

//Minusnumbers are missing. And implementing the reverse string function.
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_numlen(n);
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n == -2147483648)
		return (handle_mmaxint(str));
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (i < len - 1)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	*test;
	int		num;

	num = -214748364;
	test = ft_itoa(num);
	printf("%s", test);
}
*/

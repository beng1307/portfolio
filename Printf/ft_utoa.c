/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:02:37 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/08 12:27:46 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Counts the number length.
static int	ft_numlen(long int num)
{
	unsigned int	len;

	len = 0;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	len += 2;
	return (len);
}

//Reverses the string.
static char	ft_strrev(char *str)
{
	char			temp[11];
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
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

//The function is itoa but unsigned.
char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	len;
	unsigned int	i;

	num = n;
	len = ft_numlen(num);
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

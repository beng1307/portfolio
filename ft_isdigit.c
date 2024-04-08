/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:24:21 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/03 19:02:21 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

//test
/*
#include <stdio.h>

int main(void)
{
	char	c;

	printf("Enter a character: ");
	scanf("%c",&c);

	if (isdigit(c) == 0)
	{
         printf("%c is not a digit.",c);
	}
	else
	{
		printf("%c is a digit.",c);
	}
}

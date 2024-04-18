/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:46:22 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/18 13:51:20 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
static void increment(unsigned int num, char *c)
{
	char	help;

	help = *c;
        if (*c >= 'a' && *c <= 'y')
        {
                help += num;
        }
        else if (*c == 'z')
        {
                help = 'a';
        }
	*c = help;
}

static void decrement(unsigned int num, char *c)
{

	printf("%c", *c);
        if (*c >= 'b' && *c <= 'z')
        {
                c -= num;
        }
        else if (*c == 'a')
        {
                c = 'z';
        }
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		f(i++, s++);
	}
}

//test
/*
#include <stdio.h>

int     main(void)
{
    char    *test;

	test = malloc(3);
   	test[0] = 'g';
	test[1] = 'g';
	test[2] = 'g';
    //ft_striteri(test, decrement);
        ft_striteri(test, increment);
        printf("%s\n", test);
        //printf("%s\n", test);
	free(test);
}
*/

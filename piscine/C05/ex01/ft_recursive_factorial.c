/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:13:36 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/31 22:44:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_recursive_factorial(int nb)
{
	if (nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	else if (nb < 0)
		return (0);
	return (1);
}

/*int main(int ac, char *av[])
{
	int	nb;
	
	ac = 2;
	nb = atoi(av[1]);
	printf("%d", ft_recursive_factorial(nb));
}*/

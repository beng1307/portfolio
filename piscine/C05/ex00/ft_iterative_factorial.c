/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:27:52 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/31 22:42:01 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb >= 0)
	{
		while (nb > 0)
		{
			factorial *= nb;
			nb--;
		}
		return (factorial);
	}
	if (nb < 0)
		return (0);
	return (factorial);
}

/*int	main(int ac, char *av[])
{
	int	nb;

	ac = 2;
	nb = atoi(av[1]);
	ft_iterative_factorial(nb);
	printf("%d", ft_iterative_factorial(nb));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:53:51 by bgretic           #+#    #+#             */
/*   Updated: 2024/02/01 10:52:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_find_prime(int nb)
{
	long	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i * i <= nb)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (nb >= 2)
	{
		if (ft_find_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}

/*int	main(int ac, char *av[])
{
	int	nb;

	ac = 2;
	nb = atoi(av[1]);
	printf("%d", ft_find_next_prime(nb));
}*/

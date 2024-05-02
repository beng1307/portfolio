/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:33:02 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/31 21:23:01 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (result);
}

/*int	main(int ac, char *av[])
{
	int	nb;
	int	power;

	ac = 3;
	nb = atoi(av[1]);
	power = atoi(av[2]);
	printf("%d", ft_iterative_power(nb, power));
}*/

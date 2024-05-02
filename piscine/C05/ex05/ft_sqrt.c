/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:03:50 by bgretic           #+#    #+#             */
/*   Updated: 2024/02/01 10:54:03 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_sqrt(int nb)
{
	long	i;
	long	nbr;

	i = 0;
	nbr = nb;
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);
	if (nbr > 1)
	{
		{
			while (i + i <= nb)
			{
				if (i * i == nbr)
					return (i);
				i++;
			}
		}
	}
	return (0);
}

/*int	main(int ac, char *av[])
{
	int nb;	

	ac = 2;
	nb = atoi(av[1]);
	printf("%d", ft_sqrt(nb));
}*/

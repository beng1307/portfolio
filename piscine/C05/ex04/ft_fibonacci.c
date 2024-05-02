/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 02:23:24 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/31 23:00:00 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <stdio.h>*/

int	ft_fibonacci(int index)
{
	if (index == 1 || index == 2)
		return (1);
	else if (index < 0)
		return (-1);
	else if (index > 0)
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	else
		return (0);
}

/*int	main(int ac, char *av[])
{
	int	index;

	ac = 2;
	index = atoi(av[1]);
	printf("%d", ft_fibonacci(index));
}*/

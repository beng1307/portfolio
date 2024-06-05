/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:46:00 by tluegham          #+#    #+#             */
/*   Updated: 2024/01/14 15:05:43 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	rush(int x, int y);

int	main(int ac, char **av)
{
	size_t	arg1;
	size_t	arg2;

	if (ac == 3)
	{
		arg1 = atoi(av[1]);
		arg2 = atoi(av[2]);
		rush(arg1, arg2);
	}
	return (0);
}
